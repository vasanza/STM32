/*
 * usart.h
 *
 *  Created on: 1 jul. 2023
 *      Author: HP VICTUS
 */

#ifndef USART_H_
#define USART_H_


#include "STM32F446xx.h"
#include <stdint.h>

void uart2_tx_init(void);
void uart2_write(int ch);
char uart2_read(void);




#endif /* USART_H_ */
