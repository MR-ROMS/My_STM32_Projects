#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "main.h"

void Ultrasonic_Setup(void);
uint32_t Ultrasonic_Read(void);
void Ultrasonic_Print(uint32_t dist);

#endif
