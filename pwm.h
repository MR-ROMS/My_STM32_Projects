#ifndef PWM_H
#define PWM_H

#include "main.h"
#include <stdint.h>

/*
 * TIM2 CH1 → PA5 (Motor A)
 * TIM2 CH2 → PB3 (Motor B)
 * 84MHz APB1 timer clock
 * PSC=16 → 5MHz tick; ARR=999 → 5kHz PWM (200µs period)
 */
#define PWM_PSC     16
#define PWM_ARR     999
#define PWM_MAX     PWM_ARR

void PWM_Setup(void);
void PWM_WriteA(uint32_t duty);
void PWM_WriteB(uint32_t duty);

#endif
