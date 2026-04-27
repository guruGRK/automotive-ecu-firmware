#include "stm32f4.h"
#include "rcc.h"

void RCC_EnableGPIOA(void)
{
    RCC->AHB1ENR |= (1 << 0);
}

void RCC_EnableADC1(void)
{
    RCC->APB2ENR |= (1 << 8);
}
