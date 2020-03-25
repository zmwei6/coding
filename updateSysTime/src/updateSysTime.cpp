/*
 *  Copyright (c) 2018, NXM Labs Inc.
 *
 *  updateSysTime.cpp
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
#include "linux/rtc.h"
#include <time.h>
#include <sys/time.h>

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
	int fd, fd2, cnt, rv, yy, mn, dd, dw, hh, mm, ss;
	const char GPSSTATUS_CMD[] = {"AT!GPSSTATUS?\r"};
	char ack[64], pro[8], *str;
    struct timeval timeout;
    struct tm rtc_tm;
    struct timeval now;
    int retv = 0;

	fd = open("/dev/ttyUSB2", O_RDWR | O_NOCTTY | O_NONBLOCK | O_SYNC, 0);
	if(fd == -1)
	{
        printf("open(\"/dev/ttyUSB2\") failed!!\n");
	    return (-1);
	}
	comm_config(fd, B115200);

    /* Write GPSAUTOSTART */
    cnt = write(fd, GPSSTATUS_CMD, strlen(GPSSTATUS_CMD));
    tcdrain(fd);		//make sure data is send out the same function as O_SYNC
    usleep(100000);
	FD_ZERO(&rd);
	FD_SET(fd, &rd);
	timeout.tv_sec = 0;
	timeout.tv_usec = 100000;
	rv = select(fd + 1, &rd, NULL, NULL, &timeout);
	if (rv > 0 && FD_ISSET(fd, &rd))
    {
	  cnt = read(fd, ack, 64);
	  str = strstr(ack, "Current time:");	// str: "Current time: 2018 04 20 4 19:46:25" - UTC
	  if(str)
	  {
		memset(pro, 0, 8);
        strncpy(pro, (const char*)(str + 14), 4);
        yy = strtoul(pro, NULL, 0);
		memset(pro, 0, 8);
        strncpy(pro, (const char*)(str + 19), 2);
        mn = strtoul(pro, NULL, 0);
		memset(pro, 0, 8);
        strncpy(pro, (const char*)(str + 22), 2);
        dd = strtoul(pro, NULL, 0);
		memset(pro, 0, 8);
        strncpy(pro, (const char*)(str + 25), 1);	// day of week: 0 - 6
        dw = strtoul(pro, NULL, 0);
		memset(pro, 0, 8);
        strncpy(pro, (const char*)(str + 27), 2);
        hh = strtoul(pro, NULL, 0);
		memset(pro, 0, 8);
        strncpy(pro, (const char*)(str + 30), 2);
        mm = strtoul(pro, NULL, 0);
		memset(pro, 0, 8);
        strncpy(pro, (const char*)(str + 33), 2);
        ss = strtoul(pro, NULL, 0);
	  }
	  else
		printf("Cannot get GPS Status!\n");
    }
	else
	  printf("Cannot get GPS Status!\n");


	if((fd2 = open("/dev/rtc0", O_RDONLY)) > 0)
	{
	 	rtc_tm.tm_year = yy - 1900;
		rtc_tm.tm_mon = mn - 1;
		rtc_tm.tm_mday = dd;
		rtc_tm.tm_wday = dw;
		rtc_tm.tm_hour = hh;
		rtc_tm.tm_min = mm;
		rtc_tm.tm_sec = ss;
        now.tv_sec = mktime(&rtc_tm);
    	now.tv_usec = 0;
        retv += settimeofday(&now, NULL);					//update system time
        if(retv == 0)
      	  printf("Time is set: %s", ctime(&now.tv_sec));
		if(ioctl(fd2, RTC_SET_TIME, &rtc_tm) == -1)			//update RTC
		  printf("Update RTC failed!\n");
		close(fd2);
	}

	close(fd);
	return 0;
}
