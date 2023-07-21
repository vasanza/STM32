/*
 * usart.h
 *
 *  Created on: 1 jul. 2023
 *      Author: HP VICTUS
 */

#ifndef USART_DISC_H_
#define USART_DISC_H_

#include <stdint.h>
#include "STM32F429xx.h"


void uart1_tx_init(void);
void uart1_write(int ch);
char uart1_read(void);


#endif /* USART_DISC_H_ */
