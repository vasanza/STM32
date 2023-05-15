# Nest courses
- https://www.docker.com/
- https://www.jenkins.io/
- https://www.influxdata.com/
- https://grafana.com/
- OTA
- https://www.qt.io/

# STM32
- Modelo: NUCLEO-F446RE
- Processor: STM32F446RE MCU, Arm® Cortex®-M4 core at 180 Mhz.
- Link: https://www.st.com/en/evaluation-tools/nucleo-f446re.html
- Course: https://www.udemy.com/course/embedded-systems-bare-metal-programming/?start=720#overview

# All features
- Common features
-- STM32 microcontroller in an LQFP64 or LQFP48 package
-- 1 user LED shared with ARDUINO®
-- 1 user and 1 reset push-buttons
-- 32.768 kHz crystal oscillator
- Board connectors:
- -- ARDUINO® Uno V3 expansion connector
-- ST morpho extension pin headers for full access to all STM32 I/Os
-- Flexible power-supply options: ST-LINK USB VBUS or external sources
-- On-board ST-LINK debugger/programmer with USB re-enumeration capability: mass storage, Virtual COM port, and debug port
-- Comprehensive free software libraries and examples available with the STM32Cube MCU Package
-- Support of a wide choice of Integrated Development Environments (IDEs) including IAR Embedded Workbench®, MDK-ARM, and STM32CubeIDE
- Board-specific features
-- External SMPS to generate Vcore logic supply
-- 24 MHz or 48 MHz HSE
-- User USB Device full speed, or USB SNK/UFP full speed
-- Cryptography
- Board connectors:
-- External SMPS experimentation dedicated connector
-- USB Type-C®, Micro-B, or Mini-B connector for the ST-LINK
-- USB Type-C® user connector
-- MIPI® debug connector

# Plan de desarrollo
## Dia1
- Recursos Iniciales
- Cuenta Udemy
- Plataforma de Slack: https://arm-hablar.slack.com/join/shared_invite/zt-1u4l3fapw-wJwJlJCWuFDt8X0lclNJlw 
- IDE: STM32CubeIDE 1.11.2
## Dia2
- Example # 1 GPIO Led
-Detail:
--UART1 TX PA9
--UART1 RX PA10
- Process
-- Clock Source: AHB1, APB1
-- GPIOEN, AF7, UARTEN
- Code:
//
#include <stdint.h>
#include "stm32f4xx.h"

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
//
