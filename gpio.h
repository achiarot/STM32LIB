/*
gpio.h
STM32F103x Libraries

Created by 			Tony Chiarot
Created on			Jan 31, 2017
Last updated on 	Feb  1, 2017

*/

#ifndef gpio_INCLUDED
#define gpio_INCLUDED

class GPIO{

	public:
		
		//This is the function to setup the GPIO pin as an input or output and their type
		//This is the main function to be used by the GPIO library to configure port pins
		void gpioMode(GPIO_Pin pin, uint8_t mode, uint8_t configuration)
		
		//Pull-up pull-down input settings
		void gpioInputPUPD(GPIO_Pin pin, uint8_t resistor_UD)

		void gpioOutput(GPIO_Pin pin)
		
		void digitalWrite(GPIO_Pin pin, uint8_t value)
		
		uint8_t digitalRead(GPIO_Pin pin)

	private:
		
		void gpioInputPull(GPIO_Pin pin, uint8_t configuration, uint8_t pull)
		
		//////////					Private register functions				//////////
		//Check that the GPIO clocks are running for the given pin/port
		void setGPIOClock(GPIO_Pin pin)
      
		//Setup the configuration register of the GPIO port and pin specified
		void setGPIOCR(GPIO_Pin pin, uint8_t mode, uint8_t configuration)
      
		void setGPIOODR(GPIO_Pin pin, uint8_t bitValue)
		
		uint8_t getGPIOIDR(GPIO_Pin pin)
};

#endif
