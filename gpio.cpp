/*
gpio.cpp
STM32F103x Libraries

Created by 			Tony Chiarot
Created on			Jan 31, 2017
Last updated on 	Feb  1, 2017

*/
//////////			#includes				//////////

#include "gpio.h"
#include "stm32f103x8.h"

/////////			#defines				//////////

//GPIO_CR BITS
//INPUT Configurations
#define ANALOG					0X00
#define FLOATING				0X01
#define PULL					0x02		//Input with a pull-up or pull-down resistor


#define PULL_DOWN				0x00
#define PULL_UP					0x01

		
//OUTPUT Configurations
#define PUSH_PULL				0X00
#define	OPEN_DRAIN				0X01
#define AF_PUSH_PULL				0X02
#define AF_OPEN_DRAIN				0X03

#define DEFAULT_CONFIG				0X01		//Default config is nothing is specified by the user for input or output

//MODE BITS
#define INPUT 					0x00
#define OUTPUT 					0x01		//10MHz max output speed
#define OUTPUT_SLOW				0x02		//2MHz max output speed
#define OUTPUT_FAST				0x03		//50MHz max output speed
#define INPUT_HI				0x04		//Pull-up on the input
#define INPUT_LO				0x05		//Pull-down on the input


//////////			 Structs				//////////

typedef struct{
	(GPIO_TypeDef *) port;
	uint8_t pin;
}GPIO_Pin
	
//This is the function to setup the GPIO pin as an input or output
public void gpioMode(GPIO_Pin pin, uint8_t mode, uint8_t configuration){
	if(mode = INPUT){
		gpioInput(pin, configuration)
	}
	else{
		gpioOutput(pin, mode, 
	}
}

public void gpioMode(GPIO_Pin pin, uint8_t mode){
	gpioMode(pin, mode, DEFAULT_CONFIG)
}

public void gpioInput(GPIO_Pin pin, uint8_t configuration

)

public void gpioOutput(GPIO_pin pin){
	
}

private void gpioInputPull(GPIO_Pin pin, uint8_t configuration, uint8_t pull){
	//Set the bits in the configuration register
	setGPIOCR(pin, INPUT, configuration);
	//now we will set the ouput data register to hi or low for the pull up/down
	setGPIOODR(pin, pull);
}


//////////					Private register functions				//////////

//Setup the configuration register of the GPIO port and pin specified
private void setGPIOCR(GPIO_Pin pin, uint8_t mode, uint8_t Configuration){
	//First we will set the configuration register for the gpio port selected
	//Clear the 4 bits we wish to replace, then or that with the configuration results
	if(pin.pin<=7){
		pin.port->CRL = (pin.port->CRL & ~0x0F<<(pin.pin*4)) | ((mode<<(pin.pin*4))|(configuration<<(2+(pin.pin*4))));
	}
	Else{
		pin.port->CRH = (pin.port->CRL & ~0x0F<<(pin.pin*4)) | ((mode<<(pin.pin*4))|(configuration<<(2+(pin.pin*4))));
	}
	
	checkGPIOClock(pin);
		
}

private void setGPIOODR(GPIO_Pin pin, uint8_t bitValue){
	//now we will set the ouput data register to hi or low
	pin.port->ODR = (pin.port->ODR & ~0x01<<pin.pin)|(bitValue<<pin.pin);
}


//Check that the GPIO clocks are running for the given pin/port
private void checkGPIOClock(GPIO_Pin pin){
	//declare any variables
	uint32_t port;
	
	//Check to see that the RCC has been update to run the correct clock for the GPIO port selected
	switch(pin.port){
		case GPIOA:
			port = IOPAEN;
			break;
		case GPIOB:
			port = IOPBEN;
			break;
		case GPIOC:
			port = IOPCEN;
			break;
		case GPIOD:
			port = IOPDEN;
			break;
		case GPIOE:
			port = IOPEEN;
			break;
		case GPIOF:
			port = IOPFEN;
			break;
		case GPIOG:
			port = IOPGEN;
			break;
	}
	//See if the port clock has been started already
	if(~(RCC->APB2ENR) & port){
		//Start the port
		RCC->APB2ENR |= port;
	}
}































