/*
 * I2C.h
 *
 *  Created on: 27 ago. 2023
 *      Author: HP VICTUS
 */

#ifndef II2C_H_
#define II2C_H_

#include "STM32F446xx.h"
#include <stdint.h>

void II2C1_init(void);
//void I2C1_byteRead(void);
void II2C1_burstRead(char saddr, char maddr, int n, char* data);
void II2C1_burstWrite(char saddr, char maddr, int n, char* data);
void II2C1_byteRead(char saddr, char maddr, char* data);


//void II2C1_byteRead(void);


#endif /* II2C_H_ */
