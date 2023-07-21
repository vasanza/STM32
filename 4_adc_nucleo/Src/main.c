/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Victor Asanza & John Rivera
 * @brief          :
 ******************************************************************************
 * Example: ADC
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "STM32F446xx.h"
//#include "STM32F429xx.h"
//#include "STM32F4.h"

#define GPIOAEN 		(1U<<0)
#define ADC1EN 			(1U<<8)
#define ADC_CH1			(1U<<0)
#define ADC_SEQ_LEN_1 	0X00
#define CR2_ADON		(1U<<0)
#define CR2_SWSTART 	(1U<<30)
#define SR_EOC			(1U<<1)

uint32_t sensor_value;

void pa1_adc_init (void);
void start_convertion(void);
uint32_t adc_read(void);

int main (void)
{
	pa1_adc_init();

	while(1)
	{
		start_convertion();
		sensor_value = adc_read();
		//for (int var = 0; var < 100000; ++var)
		//{}
	}
}


void pa1_adc_init (void)
{
	//Configure ADC GPIO pin

	//Enable RCC access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	//Enable RCC access to ADC
	//Set MODER PA1 to analog
	GPIOA->MODER |=   (1U<<2); // set to 1
	GPIOA->MODER |=  (1U<3);   // set to 1

	//Configure de ADC module
	//RCC->AHB1ENR |= ADC1EN;
	RCC->APB2ENR |= ADC1EN;
	//Configure ADC parameters

	//conversion sequence  start //13.13.9 ADC regular sequence register 1 (ADC_SQR1)
	ADC1->SQR3 = ADC_CH1;
	//Conversion sequence length
	ADC1-> SQR1 = ADC_SEQ_LEN_1;
	//Enable ADC module  //13.13.3 ADC control register 2 (ADC_CR2)
	ADC1-> CR2 |= CR2_ADON;
}

void start_convertion(void)
{
	//start ADc convertion //13.13.3 ADC control register 2 (ADC_CR2)
	ADC1-> CR2 |= CR2_SWSTART;

}
uint32_t adc_read(void)
{
	//wait for the conversion to be complete //13.13.1 ADC status register (ADC_SR)
	while(!(ADC1->SR & SR_EOC))
	{}
	return ADC1->DR;

	//Read convert result
}
