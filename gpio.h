/*
gpio.h
STM32F103x Libraries

Created by 			Tony Chiarot
Created on			Jan 31, 2017
Last updated on 	Feb  1, 2017

*/

#ifndef gpio_INCLUDED
#define gpio_INCLUDED
#include "stm32f103x8.h"

/////////			#defines				//////////

//GPIO_CR BITS
//INPUT Configurations
#define ANALOG							0X00
#define FLOATING						0X01
#define PU_PD								0x02		//Input with a pull-up or pull-down resistor

#define PULL_DOWN						0x00
#define PULL_UP							0x01
		
//OUTPUT Configurations
#define PUSH_PULL						0X00
#define	OPEN_DRAIN					0X01
#define AF_PUSH_PULL				0X02
#define AF_OPEN_DRAIN				0X03

#define DEFAULT_CONFIG			0X01		//Default config is nothing is specified by the user for input or output

//MODE BITS
#define INPUT 							0x00
#define OUTPUT 							0x01		//10MHz max output speed
#define OUTPUT_SLOW					0x02		//2MHz max output speed
#define OUTPUT_FAST					0x03		//50MHz max output speed
#define INPUT_HI						0x04		//Pull-up on the input
#define INPUT_LO						0x05		//Pull-down on the input
	
#define LO									0x00
#define HI									0x01

typedef struct{
	//Pointer to the GPIO registers
	GPIO_TypeDef * port;
	uint8_t pin;
} GPIO_Pin;
		
////////										GPIO FUNCTIONS										//////////
	//This is the function to setup the GPIO pin as an input or output and their type
		//This is the main function to be used by the GPIO library to configure port pins
		void gpioMode(GPIO_Pin pin, uint8_t mode, uint8_t configuration);
		
		//Pull-up pull-down input settings
		void gpioInputPUPD(GPIO_Pin pin, uint8_t resistor_UD);

		void gpioOutput(GPIO_Pin pin);
		
		void digitalWrite(GPIO_Pin pin, uint8_t value);
		
		uint8_t digitalRead(GPIO_Pin pin);

	//These are used internally by this library.  These should not be used externally in programs (though I'm not stopping you)
		
		void gpioInputPull(GPIO_Pin pin, uint8_t configuration, uint8_t pull);
		
		//////////					Private register functions				//////////
		//Check that the GPIO clocks are running for the given pin/port
		void setGPIOClock(GPIO_Pin pin);
      
		//Setup the configuration register of the GPIO port and pin specified
		void setGPIOCR(GPIO_Pin pin, uint8_t mode, uint8_t configuration);
      
		void setGPIOODR(GPIO_Pin pin, uint8_t bitValue);
		
		uint8_t getGPIOIDR(GPIO_Pin pin);

#endif
