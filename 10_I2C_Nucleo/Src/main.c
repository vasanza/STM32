#include <II2C.h>
#include <stdint.h>
#include <stdio.h>
#include "STM32F446xx.h"
#include "usart.h"
#include "adxl345-2.h"
//#include "stm32f4.h"

char key;


int16_t x,y,z;
float xg,yg,zg;
extern uint8_t data_rec[6];
//const float FOUR_G_SCALE_FACT = 0.0078;

////////////////////////////Programa general
int main (void)
{

	//I2C
	aadxl_init();
	while(1)
	{
		aadxl_read_values(DATA_START_ADDR);
		x = ((data_rec[1]<<8) | data_rec[0]);
		y = ((data_rec[3]<<8) | data_rec[2]);
		z = ((data_rec[5]<<8) | data_rec[4]);

		xg = (x*0.0078);
		yg = (y*0.0078);
		zg = (z*0.0078);
	}










	//USART

	/*
	uart2_tx_init();
	while(1)
	{
		key = uart2_read();
		if (key == '1')
		{
			uart2_write('C');
			for (int var = 0; var < 100000; ++var)
			{
			}
		}
	}
	*/
	/////////////////////////////////////////////
	/*while(1)
	{
		uart2_write('C');
		for (int var = 0; var < 100000; ++var)
		{
		}
	}*/


}
///////////////////////////////

