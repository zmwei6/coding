/*
 *  Copyright (c) 2018, NXM Labs Inc.
 *
 *  updateSysTime.cpp
 *
 *  Created on: 2018-03-02 for OBDC project
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

#define RSSI_BASE	-113

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
	const char KEY_CMD[] = {"AT!ENTERCND=\"A710\"\r"};
	const char IMEI_CMD[] = {"AT+GSN\r"};		/* requery IMEI number */
	const char ICCID_CMD[] = {"AT!ICCID?\r"};	/* requery ICCIC number */
	const char RSSI_CMD[] = {"AT+CSQ\r"};	/* requery RSSI value */
	char imei[40] = {0}, iccid[60] = {0}, rssi[30] = {0}, pro[256];
	const char GCT_GETPROFILE[] = {"AT+CGDCONT?\r"};
	const char GCT_SETPROFILE[] = {"AT+CGDCONT=1,\"IPV4V6\",\"ltemobile.apn\",\"\",0,0,0,0,0,0,0,0,0\r"};
//	const char GCT_IPADDR_CMD[] = {"AT+CGPADDR\r"};
	const char GCT_IMEI_CMD[] = {"AT+CGSN\r"};
	const char GCT_ICCID_CMD[] = {"AT%GICCID\r"};
	char ok, *str;
	int fd, cnt, rv, rssi_val = 0;
	unsigned long offset = 0;
    struct timeval timeout;
    fd = open("/dev/ttyUSB2", O_RDWR | O_NOCTTY | O_NONBLOCK | O_SYNC, 0);
	if(fd == -1)
	{
        printf("open(\"/dev/ttyUSB2\") failed!!\n");
	    close(fd);
	    fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NONBLOCK | O_SYNC, 0);
	    if(fd == -1)
	    {
		  printf("open(\"/dev/ttyACM0\") failed!!\n");
		  close(fd);
	      exit (-1);
	    }
		comm_config(fd, B115200);

		cnt = write(fd, GCT_GETPROFILE, strlen(GCT_GETPROFILE));
	    tcdrain(fd);
	    usleep(100000);
		FD_ZERO(&rd);
		FD_SET(fd, &rd);
		timeout.tv_sec = 0;
		timeout.tv_usec = 100000;
		rv = select(fd + 1, &rd, NULL, NULL, &timeout);
		if (rv > 0 && FD_ISSET(fd, &rd))
	    {
		  cnt = read(fd, pro, 256);
		  printf("%s\n", pro);
	    }
		else
		  printf("Cannot get Profile !\n");

		tcflush(fd, TCIFLUSH);
		if(!strstr((const char*)pro, "ltemobile.apn"))	//Do not set Profile
		{
		  cnt = write(fd, GCT_SETPROFILE, strlen(GCT_SETPROFILE));
	      tcdrain(fd);
	      usleep(100000);
		}

		/* Read RSSI */
		tcflush(fd, TCIFLUSH);
	    cnt = write(fd, RSSI_CMD, strlen(RSSI_CMD));
	    tcdrain(fd);		//make sure data is send out the same function as O_SYNC
	    usleep(100000);
		FD_ZERO(&rd);
		FD_SET(fd, &rd);
		timeout.tv_sec = 0;
		timeout.tv_usec = 100000;
		rv = select(fd + 1, &rd, NULL, NULL, &timeout);
		if (rv > 0 && FD_ISSET(fd, &rd))
	    {
		  cnt = read(fd, rssi, 20);
		  while(rssi[offset++] != ':');
		  offset++;		//skip ' '
		  while((rssi[offset] >= 0x30) && (rssi[offset] <= 0x39)) {
		    rssi_val = (rssi[offset] - 0x30) + rssi_val*10;
		    offset++;
		  }
		  if(rssi_val == 99)
	        printf("RSSI not detectable!\n");
		  else
	        printf("RSSI : %d dBm\n", rssi_val*2 + RSSI_BASE);
	    }
		else
		  printf("Cannot get RSSI# !\n");

		tcflush(fd, TCIFLUSH);
		cnt = write(fd, GCT_IMEI_CMD, strlen(GCT_IMEI_CMD));
	    tcdrain(fd);
	    usleep(100000);
		FD_ZERO(&rd);
		FD_SET(fd, &rd);
		timeout.tv_sec = 0;
		timeout.tv_usec = 100000;
		rv = select(fd + 1, &rd, NULL, NULL, &timeout);
		if (rv > 0 && FD_ISSET(fd, &rd))
	    {
		  cnt = read(fd, imei, 40);
		  printf("%s\n", imei);
	    }
		else
			printf("Cannot get IMEI# !\n");

		tcflush(fd, TCIFLUSH);
	    cnt = write(fd, GCT_ICCID_CMD, strlen(GCT_ICCID_CMD));
	    tcdrain(fd);
	    usleep(100000);
		FD_ZERO(&rd);
		FD_SET(fd, &rd);
		timeout.tv_sec = 0;
		timeout.tv_usec = 100000;
		rv = select(fd + 1, &rd, NULL, NULL, &timeout);
		if (rv > 0 && FD_ISSET(fd, &rd))
	    {
		  cnt = read(fd, iccid, 60);
		  printf("%s\n", iccid);
	    }
		else
		  printf("Cannot get ICCID# !\n");
		close(fd);
		return 0;
	}
	comm_config(fd, B115200);

    cnt = write(fd, KEY_CMD, strlen(KEY_CMD));
    tcdrain(fd);
    usleep(100000);

	/* discard response OK */
	FD_ZERO(&rd);
	FD_SET(fd, &rd);
	timeout.tv_sec = 0;
	timeout.tv_usec = 100000;
	rv = select(fd + 1, &rd, NULL, NULL, &timeout);
	if (rv > 0 && FD_ISSET(fd, &rd))
	{
		while(read(fd, &ok, 1) > 0)
		{
		  if(ok == 'O')
		  {
			cnt = read(fd, &ok, 1);
			if(ok == 'K')
			{
			  while(read(fd, &ok, 1) > 0);	// no more char in the buffer
			  break;
			}
			else
			  continue;
		  }
		}
	}

    /* Read RSSI */
    cnt = write(fd, RSSI_CMD, strlen(RSSI_CMD));
    tcdrain(fd);		//make sure data is send out the same function as O_SYNC
    usleep(100000);
	FD_ZERO(&rd);
	FD_SET(fd, &rd);
	timeout.tv_sec = 0;
	timeout.tv_usec = 100000;
	rv = select(fd + 1, &rd, NULL, NULL, &timeout);
	if (rv > 0 && FD_ISSET(fd, &rd))
    {
	  cnt = read(fd, rssi, 20);
	  while(rssi[offset++] != ':');
	  offset++;		//skip ' '
	  while((rssi[offset] >= 0x30) && (rssi[offset] <= 0x39)) {
	    rssi_val = (rssi[offset] - 0x30) + rssi_val*10;
	    offset++;
	  }
	  if(rssi_val == 99)
        printf("RSSI not detectable!\n\n");
	  else
        printf("RSSI: %d dBm\n", rssi_val*2 + RSSI_BASE);
    }
	else
	  printf("Cannot get RSSI# !\n");

    /* Read IMEI */
    cnt = write(fd, IMEI_CMD, strlen(IMEI_CMD));
    tcdrain(fd);		//make sure data is send out the same function as O_SYNC
    usleep(100000);
	FD_ZERO(&rd);
	FD_SET(fd, &rd);
	timeout.tv_sec = 0;
	timeout.tv_usec = 100000;
	rv = select(fd + 1, &rd, NULL, NULL, &timeout);
	if (rv > 0 && FD_ISSET(fd, &rd))
    {
	  cnt = read(fd, imei, 40);
	  str = strstr((const char*)imei, "AT+GSN");
	  if(str)
	  {
		memset(pro, 0, 256);
        strncpy(pro, (const char*)(str + 9), 15);
        printf("IMEI: %s\n", pro);
	  }
	  else
		printf("Cannot get IMEI# !\n");
    }
	else
	  printf("Cannot get IMEI# !\n");

	/* Read ICCID */
	cnt = write(fd, ICCID_CMD, strlen(ICCID_CMD));
	tcdrain(fd);		//make sure data is send out the same function as O_SYNC
    usleep(100000);
	FD_ZERO(&rd);
	FD_SET(fd, &rd);
	/* block until input becomes available */
	timeout.tv_sec = 0;
	timeout.tv_usec = 100000;		//100 ms
	rv = select(fd + 1, &rd, NULL, NULL, &timeout);
	if (rv > 0 && FD_ISSET(fd, &rd))
    {
	  cnt = read(fd, iccid, 60);
	  str = strstr((const char*)iccid, "ICCID:");
	  if(str)
	  {
		memset(pro, 0 ,256);
        strncpy(pro, (const char*)str, 30);
        printf("%s\n", pro);
	  }
	  else
		printf("Cannot get ICCID# !\n");
    }
	else
	  printf("Cannot get ICCID# !\n");

	close(fd);
	return 0;
}
