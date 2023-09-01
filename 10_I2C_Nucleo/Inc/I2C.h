/*
 * I2C.h
 *
 *  Created on: 27 ago. 2023
 *      Author: HP VICTUS
 */

#ifndef I2C_H_
#define I2C_H_

#include "STM32F446xx.h"
#include <stdint.h>

void I2C1_init (void);
void I2C1_byteRead(void);
//void II2C1_byteRead(void);


#endif /* I2C_H_ */
