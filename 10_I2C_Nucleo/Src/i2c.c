/*
 * i2c.c
 *
 *  Created on: 27 ago. 2023
 *      Author: HP VICTUS
 */

#include "I2C.h"

#define GPIOBEN (1U<<1)
#define I2C1EN (1U<<21)
#define I2C_100KHz	80	//APB1 A 16MHZ  for standard mode
//#define I2C_400KHz	20	//APB1 A 16MHZ for fast mode
//#define I2C_100KHz	10	//APB1 A 2MHZ

#define MD_max_rise_time 17
#define CR1_PE (1U<<0)

#define SR2_BUSY (1U<<1)
#define CR1_START (1U<<8)
#define SR2_BUSY  	(1U<<1)
#define CR1_START  	(1U<<8)
#define SR1_SB  	(1U<<0)
#define SR1_ADDR  	(1U<<1)
#define SR1_TXE  	(1U<<7)
#define CR1_ACK  	(1U<<10)
#define CR1_STOP  	(1U<<9)
#define SR1_RXNE  	(1U<<6)


/*
 * Alternate function
 * PB8 --- SCL
 * PB9 --- SDA
 * */

void I2C1_init(void)
{
	//Enable clock I2C1
	//PB8 and PB9 mode to alternate function
	//PB8 and PB9 output type open drain
	//PB8 and PB9 enable pull up


	//Enable clock access to GPIOB*/

RCC -> AHB1ENR |=GPIOBEN;

/*Set PB8 and PB9 mode to alternate function*/
//Table 11. Alternate function (continued)

GPIOB->MODER &=~(1U<<16);
GPIOB->MODER |=(1U<<17);

GPIOB->MODER &=~(1U<<18);
GPIOB->MODER |=(1U<<19);

/*Set PB8 and PB9 output type to open drain*/
GPIOB->OTYPER |=(1U<<8);
GPIOB->OTYPER |=(1U<<9);

/*Enable Pull-up for PB8 and PB9*/
GPIOB->PUPDR |=(1U<<16);
GPIOB->PUPDR &=~(1U<<17);

GPIOB->PUPDR |=(1U<<18);
GPIOB->PUPDR &=~(1U<<19);

/*Enable clock access to I2C1*/
RCC->APB1ENR |= I2C1EN;

//Slave mode peripherial
I2C1-> CR1 |= (1U<<15);
I2C1-> CR1 &= ~(1U<<15);

I2C1-> CR2 = (1U<<4); //16MHZ

//24.6.8 I2C clock control register (I2C_CCR)
I2C1-> CCR = I2C_100KHz;

//Ser rise time
I2C1-> TRISE =  MD_max_rise_time;

//enable I2C1 modeule
 I2C1-> CR1 |= CR1_PE;



}

void I2C1_byteRead(char saddr, char maddr, char* data)
{
	volatile int tmp;

	/* Wait until bus not busy */
	while (I2C1->SR2 & (SR2_BUSY)){}

	/* Generate start */
	I2C1->CR1 |= CR1_START;

	/* Wait until start flag is set */
	while (!(I2C1->SR1 & (SR1_SB))){}
	/* Transmit slave address + Write */
	I2C1->DR = saddr << 1;

	/* Wait until addr flag is set */
	while (!(I2C1->SR1 & (SR1_ADDR))){}

	/* Clear addr flag */
	tmp = I2C1->SR2;

	/* Send memory address */
	I2C1->DR = maddr;

	/*Wait until transmitter empty */
	//while (!(I2C1->SR1 & SR1_TXE)){}

	/*Generate restart */
	I2C1->CR1 |= CR1_START;

	/* Wait until start flag is set */
	while (!(I2C1->SR1 & SR1_SB)){}

}

