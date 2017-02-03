/*
gpio.h
STM32F103x Libraries

Created by 			Tony Chiarot
Created on			Jan 31, 2017
Last updated on 	Feb  1, 2017

Description:  This is a test program for the STM32 libraries I have created.4
This will be similar to blinky
*/


#include "gpio.h"
	
int main(){
	//Declare all the variables
	GPIO_Pin LED;										//This will hold the port and pin number we wish to use
	

	//Assign the port and pin for the LED
	LED.port = GPIOC;
	LED.pin = 13;
	//Initialise the pin as an output
	gpioMode(LED, OUTPUT, PUSH_PULL);
	
	//Here is where the infinite loop will reside
	while(1){
		digitalWrite(LED, HI);
		uint32_t i = 0;
		while(i < 10000000){
			i++;
		}
		digitalWrite(LED, LO);
		i = 0;
		while(i < 10000000){
			i++;
		}
	}
}
