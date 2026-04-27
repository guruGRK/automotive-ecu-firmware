#include "ecu.h"

int main(void)
{
    ECU_Init();

    while (1)
    {
        ECU_Update();
    }
}
