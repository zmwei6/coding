//============================================================================
// Name        : lm75b.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "lm75b.h"

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int set_i2c_register(int file,
                            unsigned char addr,
                            unsigned char reg,
                            unsigned char value) {

    unsigned char outbuf[2];
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[1];

    messages[0].addr  = addr;
    messages[0].flags = 0;
    messages[0].len   = sizeof(outbuf);
    messages[0].buf   = outbuf;

    /* The first byte indicates which register we'll write */
    outbuf[0] = reg;

    /*
     * The second byte indicates the value to write.  Note that for many
     * devices, we can write multiple, sequential registers at once by
     * simply making outbuf bigger.
     */
    outbuf[1] = value;

    /* Transfer the i2c packets to the kernel and verify it worked */
    packets.msgs  = messages;
    packets.nmsgs = 1;
    if(ioctl(file, I2C_RDWR, &packets) < 0) {
        perror("Unable to send data");
        return 1;
    }

    return 0;
}

static int get_i2c_register(int file,
                            unsigned char addr,
                            unsigned char reg,
                            unsigned char *val) {
    unsigned char outbuf;
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[2];

    /*
     * In order to read a register, we first do a "dummy write" by writing
     * 0 bytes to the register we want to read from.  This is similar to
     * the packet in set_i2c_register, except it's 1 byte rather than 2.
     */
    outbuf = reg;
    messages[0].addr  = addr;
    messages[0].flags = 0;
    messages[0].len   = sizeof(outbuf);
    messages[0].buf   = &outbuf;

    /* The data will get returned in this structure */
    messages[1].addr  = addr;
    messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
    messages[1].len   = sizeof(val);
    messages[1].buf   = val;

    /* Send the request to the kernel and get the result back */
    packets.msgs      = messages;
    packets.nmsgs     = 2;
    if(ioctl(file, I2C_RDWR, &packets) < 0) {
        perror("Unable to send data");
        return 1;
    }

    return 0;
}

//Read a lm75b sensor on a given temp_number or channel
float lm75bRead(int fd)
{
	int16_t temp;
    unsigned char buf[2];

    if(get_i2c_register(fd, LM75B_ADDR, TEMP_REG, buf)) {
        printf("Unable to get register!\n");
    }

	temp = (buf[0]<<8) | buf[1];
	temp >>= 5; //The LM75B temperature registers are left justified, correctly right justify them

	//The LM75B does twos compliment but has the negative bit in the wrong spot, so test for it and correct if needed
	if(temp & (1<<10))
		temp |= 0xFE00; //Set bits 9 to 15 to 1s to get this reading into real twos compliment

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
	float temperature = 0;

    //    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    sprintf(filename,"/dev/i2c-0");
    if ((file = open(filename,O_RDWR/*,mode*/)) < 0) {
        printf("Failed to open the bus.");
        /* ERROR HANDLING; you can check errno to see what went wrong */
        exit(1);
    }

    if (ioctl(file,I2C_SLAVE,LM75B_ADDR) < 0) {        // The I2C address of the LM75B
        printf("Failed to acquire bus access and/or talk to slave.\n");
        /* ERROR HANDLING; you can check errno to see what went wrong */
        exit(1);
    }

    while(1)
    {
      temperature = lm75bRead(file);
	  printf("temperature = %3.1f%sC\n", temperature, deg);
	  sleep(1);
    }

    close(file);
    return 0;
}
