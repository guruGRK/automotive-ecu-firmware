#include "stm32f4.h"
#include "gpio.h"
#include "rcc.h"

void GPIO_Init_Output(unsigned int pin)
{
    RCC_EnableGPIOA();   //Enable Clock

    GPIOA->MODER &= ~(3 << (pin * 2));

    GPIOA->MODER |=  (1 << (pin * 2));
}

void GPIO_WritePin(unsigned int pin, unsigned int value)
{
    if (value)
    {
        GPIOA->ODR |= (1 << pin);
    }
    else
    {
        GPIOA->ODR &= ~(1 << pin);
    }
}
