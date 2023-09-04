#include <II2C.h>

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
#define  SR1_BTF 	(1U<<2)

/*
 * Alternate function
 * PB8 --- SCL
 * PB9 --- SDA
 * */
void II2C1_init(void)
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

//
	GPIOB->AFR[1] &= ~(1U<<0);
	GPIOB->AFR[1] &= ~(1U<<1);
	GPIOB->AFR[1] |=  (1U<<2);
	GPIOB->AFR[1] &= ~(1U<<3);

	GPIOB->AFR[1] &= ~(1U<<4);
	GPIOB->AFR[1] &= ~(1U<<5);
	GPIOB->AFR[1] |=  (1U<<6);
	GPIOB->AFR[1] &= ~(1U<<7);


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

void II2C1_byteRead(char saddr, char maddr, char* data)
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

	//Wait until transmitter empty
	while (!(I2C1->SR1 & SR1_TXE)){}

	/*Generate restart */
	I2C1->CR1 |= CR1_START;

	/* Wait until start flag is set */
	while (!(I2C1->SR1 & SR1_SB)){}

	//Transmit slave address + READ
	I2C1 ->DR= saddr <<1 | 1;

	while(!(I2C1->SR1 & SR1_ADDR)){}

	//Disa8le acknowledga
	I2C1 -> CR1 &= ~CR1_ACK;

	//Clear addr flag
	tmp = I2C1 -> SR2;

	//Generate Stop after data received
	I2C1 -> CR1 |= CR1_STOP;

	while(!(I2C1->SR1 & SR1_RXNE)){}

	//Read data from DR
	*data++ = I2C1->DR;


}

void II2C1_burstRead(char saddr, char maddr, int n, char* data)
{
	volatile int tmp;

	/* Wait until bus not busy */
	while (I2C1->SR2 & (SR2_BUSY)){}

	/* Generate start */
	I2C1->CR1 |= CR1_START;

	/* Wait until start flag is set */
	while (!(I2C1->SR1 & SR1_SB)){}

	/* Transmit slave address + Write */
	I2C1->DR = saddr << 1;

	/* Wait until addr flag is set */
	while (!(I2C1->SR1 & SR1_ADDR)){}

	/* Clear addr flag */
	tmp = I2C1->SR2;

	/* Wait until transmitter empty */
	while (!(I2C1->SR1 & SR1_TXE)){}

	/*Send memory address */
	I2C1->DR = maddr;

	/*Wait until transmitter empty */
	while (!(I2C1->SR1 & SR1_TXE)){}

	/*Generate restart */
	I2C1->CR1 |= CR1_START;

	//wait until start flag is set
	while (!(I2C1->SR1 & SR1_SB)){}

	//transmit slave address + Read
	I2C1->DR = saddr << 1 | 1;

	//wait until addr flag is set
	while (!(I2C1->SR1 & SR1_ADDR)){}

	//clear addr flag
	tmp = I2C1 ->SR2;

	//Enable acknowledge
	I2C1 -> CR1 |= CR1_ACK;

	while (n > 0U)
	{
		/*if one byte*/
		if(n == 1U)
		{
			/* Disable Acknowledge */
			I2C1-> CR1 &= ~CR1_ACK;

			/* Generate Stop */
			I2C1-> CR1 |= CR1_STOP;

			/* Wait for RXNE flag set */
			while (!(I2C1->SR1 & SR1_RXNE)){}

			/* Read data from DR */
			*data++ = I2C1->DR;
			break;

		}

		else
		{
			/* Wait until RXNE flag is set */

			while (!(I2C1->SR1 & SR1_RXNE)){}

			/* Read data from DR +*/
			(*data++) = I2C1->DR;

			n--;
		}
	}

}
void II2C1_burstWrite(char saddr, char maddr, int n, char* data)
{
	volatile int tmp;

	/* Wait until bus not busy */
	while (I2C1->SR2 & (SR2_BUSY)){}

	/* Generate start */
	I2C1->CR1 |= CR1_START;

	/* Wait until start flag is set */
	while (!(I2C1->SR1 & (SR1_SB))){}

	/* Transmit slave address */
	I2C1->DR = saddr << 1;

	/* Wait until addr flag is set */
	while (!(I2C1->SR1 & (SR1_ADDR))){}

	/* Clear addr flag */
	tmp = I2C1->SR2;

	/* Wait until data register empty */
	while (!(I2C1->SR1 & (SR1_TXE))){}

	/* Send memory address */
	I2C1->DR = maddr;

	for (int i = 0; i< n; i++) {
		/* Wait until data register empty */
		while (!(I2C1->SR1 & (SR1_TXE))){}

		//transmit memory address
		I2C1-> DR = *data++;
	}

	//wait memory address
	while (!(I2C1->SR1 & (SR1_BTF))){}

	//Generate stop
	I2C1->CR1 |= CR1_STOP;
}

