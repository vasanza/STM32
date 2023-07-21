#include <stdint.h>
#include "STM32F429xx.h"

#define GPIOAEN (1U<<0)
#define UART2EN (1U<<17)

#define CR1_TE		(1U<<3)  //Control Register Tx Enable
//#define CR1_UR	(1U<<13) //
#define CR1_UE		(1U<<13) //
#define SR_TXE		(1U<<7)  //


#define SYS_FREQ	16000000
#define APB1_CLK	SYS_FREQ

#define UART_BAUDRATE 	115200

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t Baudrate);
void uart2_tx_init(void);
void uart2_write(int ch);


int main (void)
{
	uart2_tx_init();
	while(1)
	{
		uart2_write('J');
	}
}

void uart2_tx_init(void)
{
	//clock to gpioa
	RCC->AHB1ENR |= GPIOAEN;

	//SET PA2 to alternate function mode
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER &= ~(1U<<5);

	//PA2 Alternate function Uart tx AF07
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= (1U<<11);

	//clock to uart2
	RCC->APB1ENR |= UART2EN;

	//Configura 8audrate
	uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE);

	//Configure de transfer direction.
	USART2->CR1 = CR1_TE;


	//Enable UART module.
	USART2->CR1 = CR1_UE;

}

void uart2_write(int ch)
{
	// Asegure que tx dabta este vigente
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
