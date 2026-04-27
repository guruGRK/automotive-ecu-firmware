#include "stm32f4.h"
#include "adc.h"
#include "rcc.h"

void ADC_Init()
{
    RCC_EnableADC1();

    ADC1->CR2 |= (1 << 0);
}

unsigned int ADC_Read(unsigned int channel)
{
    ADC1->SQR3 = channel;

    ADC1->CR2 |= (1 << 30);   // Start conversion

    while (!(ADC1->SR & (1 << 1)));

    return ADC1->DR;
}
