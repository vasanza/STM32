#include <stdint.h>
#include <stdio.h>
#include "STM32F446xx.h"
//#include "STM32F429xx.h"
//#include "STM32F4.h"

#define GPIOAEN (1<<0)

int main (void)
{
	RCC->AHB1ENR |= GPIOAEN;
	GPIOA->MODER |=   (1U<<10); // set to 0
	GPIOA->MODER &=  ~(1U<11); // set to 1
	while(1)
	{
		GPIOA -> ODR |= (1<<5);
		for (int var = 0; var < 100000; ++var){}
		GPIOA -> ODR &= ~(1<<5);
		for (int var = 0; var < 100000; ++var){}
	}
}
