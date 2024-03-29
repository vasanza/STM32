#include <stdint.h>
#include "STM32F446xx.h"

#define GPIOAEN (1U<<0)		//6.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
							//Bit 0 GPIOAEN: IO port A clock enable
							//1: IO port A clock enabled
#define UART2EN (1U<<17)    //6.3.13 RCC APB1 peripheral clock enable register (RCC_APB1ENR)
							//Bit 17 USART2EN: USART2 clock enable
							//1: USART2 clock enabled

#define CR1_TE		(1U<<3)  //Control register 1 (USART_CR1) Bit 3 TE: Transmitter enable
#define CR1_UE		(1U<<13) //Control register 1 (USART_CR1) Bit 13 UE: USART enable
#define SR_TXE		(1U<<7)  //30.6.1 Status register (USART_SR) // Bit 7 TXE: Transmit data register empty


#define SYS_FREQ	16000000
#define APB1_CLK	SYS_FREQ

#define UART_BAUDRATE 	115200


static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t Baudrate);
void uart2_tx_init(void);
void uart2_write(int ch);

////////////////////////////Programa general
int main (void)
{
	uart2_tx_init();
	while(1)
	{
		uart2_write('A');
		for (int var = 0; var < 100000; ++var)
		{
		}
	}
}
///////////////////////////////

void uart2_tx_init(void)
{
	//clock to gpioa
	RCC->AHB1ENR |= GPIOAEN; //6.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)

	//SET PA2 to alternate function mode
	//7.4.1 GPIO port mode register (GPIOx_MODER) (x = A..H)
	//10: Alternate function mode
	GPIOA->MODER &= ~(1U<<4); // set to 0
	GPIOA->MODER |=  (1U<<5); // set to 1

	//PA2 Alternate function Uart tx AF07
	//7.4.9 GPIO alternate function low register (GPIOx_AFRL) (x = A..H)
	//0111: AF7
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

	//clock to uart2
	RCC->APB1ENR |= UART2EN;	//6.3.13 RCC APB1 peripheral clock enable register (RCC_APB1ENR)
								//Bit 17 USART2EN: USART2 clock enable
								//1: USART2 clock enabled

	//Configura 8audrate
	uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE);

	//Configure de transfer direction.
	USART2->CR1 = CR1_TE;


	//Enable UART module.
	USART2->CR1 |= CR1_UE;

}

void uart2_write(int ch)
{
	// Asegure que tx data este vigente
	while(!(USART2->SR & SR_TXE)){}
	//Write to transmit data register
	USART2->DR = (ch & 0XFF);
}



static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate)
{
	USARTx->BRR = compute_uart_bd(PeriphClk,Baudrate);
}
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t Baudrate)
{
	return((PeriphClk + (Baudrate/2U))/Baudrate);
}
