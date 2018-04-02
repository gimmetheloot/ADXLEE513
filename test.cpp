#include <iostream>
#include "ADXLclass.h"
#include <unistd.h>
#include <pthread.h>

using namespace std;

//main, to test the full program, creates an object of the ADXLclass class and then calls the functions to get the valut of the acceleration
int main() {
   ADXLclass chip(1,0x53);
   chip.getaccX();
	cout<<("the acceleration is ");
   chip.getaccY();
   chip.getaccZ();
   return 0;
}
