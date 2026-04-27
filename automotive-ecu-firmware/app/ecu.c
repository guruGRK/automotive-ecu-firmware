#include "ecu.h"
#include "gpio.h"
#include "adc.h"
#include "board.h"

static ECU_State current_state;

void ECU_Init()
{
    GPIO_Init_Output(FAN_PIN);
    GPIO_Init_Output(BUZZER_PIN);

    ADC_Init();

    current_state = NORMAL;    //Default state
}

void ECU_Update()
{
    unsigned int temp = ADC_Read(TEMP_CHANNEL);

    if (temp < -40 || temp > 150)
    {
        current_state = FAULT;
    }
    else if (temp > 90)
    {
        current_state = OVERHEAT;
    }
    else
    {
        current_state = NORMAL;
    }


    switch (current_state)
    {
        case NORMAL:
            GPIO_WritePin(FAN_PIN, 0);
            GPIO_WritePin(BUZZER_PIN, 0);
            break;

        case OVERHEAT:
            GPIO_WritePin(FAN_PIN, 1);
            GPIO_WritePin(BUZZER_PIN, 1);
            break;

        case FAULT:
            GPIO_WritePin(FAN_PIN, 0);
            GPIO_WritePin(BUZZER_PIN, 1);
            break;
    }
}
