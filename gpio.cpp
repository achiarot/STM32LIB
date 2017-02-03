/*
gpio.cpp
STM32F103x Libraries

Created by 			Tony Chiarot
Created on			Jan 31, 2017
Last updated on 	Feb  1, 2017

*/
//////////			#includes				//////////

#include "gpio.h"

//////////					Configuration/initialization Functions					//////////
//These are the functions to setup the GPIO pin as an input or output and their type
//This is the main function to be used by the GPIO library to configure port pins
//You must use one of the "gpio" functions to initialize the pin you want to use
void gpioMode(GPIO_Pin pin, uint8_t mode, uint8_t configuration){
	if (mode == INPUT_HI){
		gpioInputPull(pin, configuration, PULL_UP);
	}
	else if (mode == INPUT_LO){
		gpioInputPull(pin, configuration, PULL_DOWN);
	}
	else{
		setGPIOCR(pin, mode, configuration);
	}
}
		
//Pull-up pull-down input settings
void gpioInputPUPD(GPIO_Pin pin, uint8_t resistor_UD){
	gpioInputPull(pin, PU_PD, resistor_UD);
}

void gpioOutput(GPIO_Pin pin){
	
}
		
//////////					Read from and Write to the pin					//////////
void digitalWrite(GPIO_Pin pin, uint8_t value){
	setGPIOODR(pin, value);
}
		
uint8_t digitalRead(GPIO_Pin pin){
	return getGPIOIDR(pin);
}

void gpioInputPull(GPIO_Pin pin, uint8_t configuration, uint8_t pull){
	//Set the bits in the configuration register
	setGPIOCR(pin, INPUT, configuration);
	//now we will set the ouput data register to hi or low for the pull up/down
	setGPIOODR(pin, pull);
}
		
		
//////////					Private register functions				//////////
	//Check that the GPIO clocks are running for the given pin/port
void setGPIOClock(GPIO_Pin pin){
	//declare any variables
	uint32_t port;
	RCC_TypeDef * RCCntrl = RCC;
	
	//Check to see that the RCC has been update to run the correct clock for the GPIO port selected
	if (pin.port == GPIOA){
		port = IOPAEN;
	}
	else if(pin.port == GPIOB){
		port = IOPBEN;
	}
	else if(pin.port == GPIOC){
		port = IOPCEN;
	}
	else if(pin.port == GPIOD){
		port = IOPDEN;
	}
	else if(pin.port == GPIOE){
		port = IOPEEN;
	}
	else{
		port = 0x00000000;
	}
	//Create the pointer to the RCC registers
	//See if the port clock has been started already
	if(~(RCCntrl->APB2ENR) & port){
		//Start the port
		RCCntrl->APB2ENR |= port;
	}
}
					//Setup the configuration register of the GPIO port and pin specified
void setGPIOCR(GPIO_Pin pin, uint8_t mode, uint8_t configuration){
	//make sure the clock has been turned on for the GPIO port for the desired pin
	setGPIOClock(pin);
	
	//First we will set the configuration register for the gpio port selected
	//Clear the 4 bits we wish to replace, then or that with the configuration results
	if(pin.pin<=7){
		pin.port->CRL = (pin.port->CRL & ~0x0F<<(pin.pin*4)) | ((mode<<(pin.pin*4))|(configuration<<(2+(pin.pin*4))));
	}
	else{
		pin.port->CRH = (pin.port->CRL & ~0x0F<<((pin.pin-8)*4)) | ((mode<<((pin.pin-8)*4))|(configuration<<(2+((pin.pin-8)*4))));
	}
}
	
void setGPIOODR(GPIO_Pin pin, uint8_t bitValue){
	//now we will set the ouput data register to hi or low
	pin.port->ODR = (pin.port->ODR & ~0x01<<pin.pin)|(bitValue<<pin.pin);
}

uint8_t getGPIOIDR(GPIO_Pin pin){
	return (pin.port->IDR & 0x01<<pin.pin)>>pin.pin; 
}

