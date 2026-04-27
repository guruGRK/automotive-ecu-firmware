#ifndef ECU_H
#define ECU_H

typedef enum {
    NORMAL = 0,
    OVERHEAT,
    FAULT
} ECU_State;

void ECU_Init();
void ECU_Update();

#endif
