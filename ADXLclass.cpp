#include "ADXLclass.h"
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdio.h>

//first define all the register addresses and what each one contains, I got these from the data sheet for the ADXL345 chip

#define DEVID          0x00   //Device ID
#define THRESH_TAP     0x1D   //Tap Threshold
#define OFSX           0x1E   //X-axis Offset
#define OFSY           0x1F   //Y-axis Offset
#define OFSZ           0x20   //Z-axis Offset
#define DUR            0x21   //Tap duration
#define LATENT         0x22   //Tap latency
#define WINDOW         0x23   //Tap window
#define THRESH_ACT     0x24   //Activity threshold
#define THRESH_INACT   0x25   //Threshold inactivity
#define TIME_INACT     0x26   //Inactivity time
#define ACT_INACT_CTL  0x27   //control for activity and inactivity
#define THRESH_FF      0x28   //Free-fall threshold
#define TIME_FF        0x29   //Free-fall time
#define TAP_AXES       0x2A   //Axis control for single tap/double tap
#define ACT_TAP_STATUS 0x2B   //Source of single tap/double tap
#define BW_RATE        0x2C   //Data rate and power mode control
#define POWER_CTL      0x2D   //Power-saving features control
#define INT_ENABLE     0x2E   //Interrupt enable control
#define INT_MAP        0x2F   //Interrupt mapping control
#define INT_SOURCE     0x30   //Source of interrupts
#define DATA_FORMAT    0x31   //Data format control
#define DATAX0         0x32   //X-axis Data 0
#define DATAX1         0x33   //X-axis Data 1
#define DATAY0         0x34   //Y-axis Data 0
#define DATAY1         0x35   //Y-axis Data 1
#define DATAZ0         0x36   //Z-axis Data 0
#define DATAZ1         0x37   //Z-axis Data 1
#define FIFO_CTL       0x38   //FIFO control
#define FIFO_STATUS    0x39   //FIFO status



ADXLclass::ADXLclass(int bus, unsigned int deviceaddress)
{

	this->deviceaddress = deviceaddress;
	this->bus = bus;
	this->accX = 0;
	this->accY = 0;
	this->accZ = 0;
}


//function to add the two registers together, first it shifts the most sig bit left by 8 bits and then performs a logical OR operation with the LSB
short ADXLclass::addlsbmsb(char msb, char lsb){
   
   return ((short)msb<<8)|(short)lsb;
}


//function that reads the chip on the pi.The function then calls the addlsbmsb function to calculate the values of the acceleration of each axis
int ADXLclass::readpi(){
	
	this->accX = this->addlsbmsb(*(reg+DATAX1), *(reg+DATAX0));
	this->accY = this->addlsbmsb(*(reg+DATAY1), *(reg+DATAY0));
	this->accZ = this->addlsbmsb(*(reg+DATAZ1), *(reg+DATAZ0));	
	return 0;
}

	
