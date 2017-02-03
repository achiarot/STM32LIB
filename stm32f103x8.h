/*
STM32F103x8 address register defines

This will define the registers used for the given microcontroller

Currently implemented:
GPIO
RCC
TIM

Created by 				Tony Chiarot
Created on 				Jan 31, 2017
Last updated on 	Jan 31, 2017

*/

//////////				Guard against #include				\\\\\\\\\\

#ifndef stm32f103x_INCLUDED
#define stm32f103x_INCLUDED

//////////			Included Libraries and files		\\\\\\\\\\

#include <stdint.h>

//////////		Typedef created for GPIO layout		\\\\\\\\\\

//GPIO TYPE
typedef struct
{
  uint32_t CRL;
  uint32_t CRH;
  uint32_t IDR;
  uint32_t ODR;
  uint32_t BSRR;
  uint32_t BRR;
  uint32_t LCKR;
} GPIO_TypeDef;

//TIMER TYPE
typedef struct
{
   uint16_t CR1;
  uint16_t  RESERVED0;
   uint16_t CR2;
  uint16_t  RESERVED1;
   uint16_t SMCR;
  uint16_t  RESERVED2;
   uint16_t DIER;
  uint16_t  RESERVED3;
   uint16_t SR;
  uint16_t  RESERVED4;
   uint16_t EGR;
  uint16_t  RESERVED5;
   uint16_t CCMR1;
  uint16_t  RESERVED6;
   uint16_t CCMR2;
  uint16_t  RESERVED7;
   uint16_t CCER;
  uint16_t  RESERVED8;
   uint16_t CNT;
  uint16_t  RESERVED9;
   uint16_t PSC;
  uint16_t  RESERVED10;
   uint16_t ARR;
  uint16_t  RESERVED11;
   uint16_t RCR;
  uint16_t  RESERVED12;
   uint16_t CCR1;
  uint16_t  RESERVED13;
   uint16_t CCR2;
  uint16_t  RESERVED14;
   uint16_t CCR3;
  uint16_t  RESERVED15;
   uint16_t CCR4;
  uint16_t  RESERVED16;
   uint16_t BDTR;
  uint16_t  RESERVED17;
   uint16_t DCR;
  uint16_t  RESERVED18;
   uint16_t DMAR;
  uint16_t  RESERVED19;
} TIM_TypeDef;

//RCC TYPE
typedef struct
{
   uint32_t CR;
   uint32_t CFGR;
   uint32_t CIR;
   uint32_t APB2RSTR;
   uint32_t APB1RSTR;
   uint32_t AHBENR;
   uint32_t APB2ENR;
   uint32_t APB1ENR;
   uint32_t BDCR;
   uint32_t CSR;
} RCC_TypeDef;

//////////					Typedefs finished						\\\\\\\\\\
//////////					Register Locations					\\\\\\\\\\

#define TIM2				(TIM_TypeDef *) 0x40000000 
#define TIM3				(TIM_TypeDef *) 0x40000400
#define TIM4				(TIM_TypeDef *) 0x40000800
//#define RTC					(RTC_TypeDef *)0x40002800
//#define WWDG				0x40002C00
//#define IWDG				0x40003000
//#define SPI2				0x40003800
//#define USART2			0x40004400
//#define USART3			0x40004800
//#define I2C1				0x40005400
//#define I2C2				0x40005800
//#define USB					0x40005C00
//#define USBCAN			0x40006000
//#define BxCAN				0x40006400
//#define BKP					0x40006C00
//#define PWR					0x40007000
//#define AFIO				0x40010000
//#define EXTI				0x40010400
#define GPIOA				(GPIO_TypeDef *) 0x40010800
#define GPIOB				(GPIO_TypeDef *) 0x40010C00
#define GPIOC				(GPIO_TypeDef *) 0x40011000
#define GPIOD				(GPIO_TypeDef *) 0x40011400
#define GPIOE				(GPIO_TypeDef *) 0x40011800
//#define ADC1				0x40012400
//#define ADC2				0x40012800
#define TIM1				(TIM_TypeDef *) 0x40012C00
//#define SPI1				0x40013000
//#define USART1			0x40013800
//#define DMA					0x40020000
#define RCC					(RCC_TypeDef *) 0x40021000
//#define FLASH				0x40022000
//#define CRC					0x40023000

//////////						RCC Constants					//////////
#define IOPAEN				(0x01<<2)
#define IOPBEN				(0x01<<3)
#define IOPCEN				(0x01<<4)
#define IOPDEN				(0x01<<5)
#define IOPEEN				(0x01<<6)
#define IOPFEN				(0x01<<7)
#define IOPGEN				(0x01<<8)

#endif
