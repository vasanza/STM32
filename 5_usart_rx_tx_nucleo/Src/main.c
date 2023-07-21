#include <stdint.h>
#include "STM32F446xx.h"
#include "usart.h"

//#include "stm32f4.h"

char key;


////////////////////////////Programa general
int main (void)
{
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

