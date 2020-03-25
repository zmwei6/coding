/*
 *  Copyright (c) 2018, NXM Labs Inc.
 *
 *  startGPS.cpp
 *
 *  Created on: 2018-04-20 for OBDC project
 *      Author: Zimin Wei
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include "linux/serial.h"

void comm_config(int uart_fd, unsigned int baudrate)
{
	struct termios oldtio, newtio;      //place for old and new port settings for serial port

	tcgetattr(uart_fd, &oldtio); 		// save current port settings
	memset(&newtio, 0, sizeof(newtio)); /* clear struct for new port settings */
	/* set new port settings for canonical input processing */
	newtio.c_cflag &= ~PARENB;			/* no parity */
	newtio.c_cflag &= ~CSTOPB;			/* 1 stop bit */
	newtio.c_cflag &= ~CSIZE;			/* CSIZE is a mask for all the data size bits */
	newtio.c_cflag &= ~CRTSCTS;			/* Disable hardware flow control */
	newtio.c_iflag &= ~(IXON | IXOFF | IXANY);     /* disable XON XOFF (for transmit and receive) */
	newtio.c_cflag = baudrate | CS8 | CLOCAL | CREAD;
	newtio.c_iflag = IGNPAR;
	newtio.c_oflag = 0;					/* Raw output */
	newtio.c_lflag = 0;					/* non-canonical, no echo, ... */
	newtio.c_cc[VMIN] = 1;				/* VMIN is the minimum amount of characters to read. */
	newtio.c_cc[VTIME] = 0;

	tcflush(uart_fd, TCIFLUSH);
	tcsetattr(uart_fd, TCSANOW, &newtio);
}

int main()
{
    fd_set rd;    /* file descriptor set */
	int fd, cnt, rv;
	const char FIX_CMD[] = {"AT!GPSFIX=1,15,10\r"};
	const char AUTO_CMD[] = {"AT!GPSAUTOSTART=1,1,15,10,5\r"};
	char ack[48];
    struct timeval timeout;
    fd = open("/dev/ttyUSB2", O_RDWR | O_NOCTTY | O_NONBLOCK | O_SYNC, 0);
	if(fd == -1)
	{
        printf("open(\"/dev/ttyUSB2\") failed!!\n");
	    return (-1);
	}
	comm_config(fd, B115200);

    /* Write GPSFIX */
    cnt = write(fd, FIX_CMD, strlen(FIX_CMD));
    tcdrain(fd);		//make sure data is send out the same function as O_SYNC
    usleep(100000);
	FD_ZERO(&rd);
	FD_SET(fd, &rd);
	timeout.tv_sec = 0;
	timeout.tv_usec = 100000;
	rv = select(fd + 1, &rd, NULL, NULL, &timeout);
	if (rv > 0 && FD_ISSET(fd, &rd))
    {
	  memset(ack, 0, 48);
	  cnt = read(fd, ack, 48);
	  if(strstr(ack, "ERROR"))
		  strncpy(ack + cnt - 2, ": Executed!\n", 11);
      printf("\n%s\n", ack);
    }
	else
	  printf("Write AT!GPSFIX failed!\n");

    /* Write GPSAUTOSTART */
    cnt = write(fd, AUTO_CMD, strlen(AUTO_CMD));
    tcdrain(fd);		//make sure data is send out the same function as O_SYNC
    usleep(100000);
	FD_ZERO(&rd);
	FD_SET(fd, &rd);
	timeout.tv_sec = 0;
	timeout.tv_usec = 100000;
	rv = select(fd + 1, &rd, NULL, NULL, &timeout);
	if (rv > 0 && FD_ISSET(fd, &rd))
    {
	  memset(ack, 0, 48);
	  cnt = read(fd, ack, 48);
      printf("\n%s\n", ack);
    }
	else
	  printf("Write AT!GPSAUTOSTART failed!\n");

	close(fd);
	return 0;
}
