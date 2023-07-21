#include <stdint.h>
#include "STM32F429xx.h"
#include "usart_disc.h"

char key;
////////////////////////////Programa general
int main (void)
{
	uart1_tx_init();
	while(1)
	{
		key = uart1_read();
		if (key == '3')
		{
			uart1_write('C');
			for (int var = 0; var < 100000; ++var)
			{
			}
		}
	}
}
///////////////////////////////Fin programa general
