#ifndef STM32F4_H
#define STM32F4_H

#define PERIPH_BASE     0x40000000
#define AHB1PERIPH_BASE 0x40020000

#define GPIOA_BASE      0x40020000
#define RCC_BASE        0x40023800
#define ADC1_BASE       0x40012000

typedef struct {
    volatile unsigned int MODER;       // 0x00
    volatile unsigned int RESERVED1[4];
    volatile unsigned int ODR;         // 0x14
} GPIO_TypeDef;

typedef struct {
    volatile unsigned int CR;           // 0x00
    volatile unsigned int RESERVED1[11];
    volatile unsigned int AHB1ENR;      // 0x30
    volatile unsigned int RESERVED2[1];
    volatile unsigned int APB2ENR;
} RCC_TypeDef;

typedef struct {
    volatile unsigned int SR;            // 0x00
    volatile unsigned int RESERVED1[1];
    volatile unsigned int CR2;           // 0x08
    volatile unsigned int RESERVED2[10];
    volatile unsigned int SQR3;          // 0x34
    volatile unsigned int RESERVED3[5];
    volatile unsigned int DR;            // 0x4C
} ADC_TypeDef;

#define GPIOA ((GPIO_TypeDef*) GPIOA_BASE)
#define RCC   ((RCC_TypeDef*) RCC_BASE)
#define ADC1 ((ADC_TypeDef*) ADC1_BASE)

#endif
