#ifndef ADXLclass_HPP_
#define ADXLclass_HPP_
#define BUFFER_SIZE 0x40
#include <iostream>


//Here is my class for the ADXL chip

class ADXLclass{

private:

//I first declare all the variables I will be using for my program, I keep these in private as I dont want them changed
int file;
int bus;
unsigned int deviceaddress;
unsigned char *reg; // pointer to each register
short accX;
short accY;
short accZ;
float pitch;
float roll;
short addlsbmsb(char lsb, char msb); // function to add two registers
void pitchroll(); // function to calculate pitch and roll




public:

//public declarations, constructor an the virtual functions i want to be used in my program
ADXLclass(int bus, unsigned int deviceaddress = 0x53);
virtual int readpi();

//function to read from registers, 
virtual unsigned char* readreg(unsigned int num, unsigned int fromAddress=0)
{
num =0;
fromAddress=0;
}
//function that returns x acceleration
virtual short getaccX()
{
return accX;
std::cout<<("been called");
}
//function that returns y acceleration
virtual short getaccY()
{
return accY;
}
//function that returns z acceleration
virtual short getaccZ()
{
return accZ;
}
//function that returns the roll
virtual short getroll()
{
return roll;
}
//function that returns the pitch
virtual short getpitch()
{
return pitch;
}
};
#endif
