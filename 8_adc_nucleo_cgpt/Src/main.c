//#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>
#include "STM32F446xx.h"

void ADC_Init(void);
uint32_t ADC_Read(void);

int main(void)
{
    while (1)
    {
    	ADC_Init();
        uint32_t adc_value = ADC_Read();
        // Haz algo con el valor leído del ADC
    }
}
void ADC_Init(void)
{
    // Habilitar el reloj para el ADC1
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    // Habilitar el reloj para el GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Configurar el pin A1 como entrada analógica
    GPIOA->MODER |= GPIO_MODER_MODER1;

    // Configurar la frecuencia de muestreo del ADC
    ADC1->CR2 |= ADC_CR2_ADON; // Habilitar el ADC
    ADC1->CR2 |= ADC_CR2_CONT; // Modo de conversión continua
    ADC1->CR2 |= ADC_CR2_SWSTART; // Iniciar la conversión

    // Configurar el canal del ADC
    ADC1->SQR3 |= 0x01; // Seleccionar el canal 1

    // Calibrar el ADC
    ADC1->CR2 |= ADC_CR2_ADON; // Habilitar el ADC
    //ADC1->CR2 |= ADC_CR2_CAL; // Iniciar la calibración
    //while (ADC1->CR2 & ADC_CR2_CAL) {} // Esperar hasta que la calibración haya terminado
}

uint32_t ADC_Read(void)
{
    ADC1->CR2 |= ADC_CR2_SWSTART; // Iniciar la conversión

    // Esperar hasta que la conversión se complete
    while (!(ADC1->SR & ADC_SR_EOC)) {}

    return ADC1->DR; // Devolver el valor convertido
}
