//============================================================================
// Name        : eeprom.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <glib.h>
//#include <glib/gprintf.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "i2c.h"

//Read a eeprom sensor on a given temp_number or channel
float eepromRead(int fd)
{
	int16_t temp;
    unsigned char buf[10] = {0};

    buf[0] = TMP_RD;
    if (write(fd,buf,1) != 1) {
        /* ERROR HANDLING: i2c transaction failed */
        printf("Failed to write TEMP_REG to i2c bus(%s).\n", strerror(errno));
        return 0.0;
    }

	// Using I2C Read
	if (read(fd,buf,2) != 2) {
		/* ERROR HANDLING: i2c transaction failed */
		printf("Failed to read from the i2c bus(%s).\n", strerror(errno));
        return 0.0;
	}
	temp = (buf[0]<<8) | buf[1];
	temp >>= 5; //The LM75BTP temperature registers are left justified, correctly right justify them

	//The LM75BTP does twos compliment but has the negative bit in the wrong spot, so test for it and correct if needed
	if(temp & (1<<10))
		temp |= 0xFC00; //Set bits 10 to 15 to 1s to get this reading into real twos compliment

	//printf("%02d\n", temp);

	//But if we want, we can convert this directly to a celsius temp reading
	//temp *= 0.125; //This is the same as a divide by 8
	//temp >>= 5; //Which is really just a shift of 5 so it's much faster and doesn't require floating point
	//Shifts may not work with signed ints (negative temperatures). Let's do a divide instead
	//temp /= 8;

	return(temp/8.0);
}

int main(void) {
    int file;
    char deg[3] = "°";
    char filename[40];
    int addr = 0x50;        // The I2C address of the EEPROM
	float val = 0;

    //    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    sprintf(filename,"/dev/i2c-0");
    if ((file = open(filename,O_RDWR/*,mode*/)) < 0) {
        printf("Failed to open the bus.");
        /* ERROR HANDLING; you can check errno to see what went wrong */
        exit(1);
    }

    if (ioctl(file,I2C_SLAVE,addr>>1) < 0) {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        /* ERROR HANDLING; you can check errno to see what went wrong */
        exit(1);
    }

    while(1)
    {
      val = eepromRead(file);
	  printf("EEPROM = %3.2f%sC\n", val, deg);
	  usleep(500000);
    }

    close(file);
    return 0;
}
