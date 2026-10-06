#ifndef SERVO_H
#define SERVO_H

#include "main.h"
#include <stdint.h>

/*
 *
 * Timer: TIM12 on PB14 (CH1) or PB15 (CH2)
 * Clock: 84MHz, PSC=83 → 1MHz tick
 * ARR=19999 → 20ms period (50Hz)
 *
 * Pulse widths (in 1µs ticks):
 *   -90° = 1000 µs (1.0ms) - Full right
 *    0°  = 1500 µs (1.5ms) - Center/Middle
 *   +90° = 2000 µs (2.0ms) - Full left
 *
 * Total range: 1000µs for 180° → 5.56µs per degree
 */
#define SERVO_PSC   83
#define SERVO_ARR   19999

#define SERVO_MIN   500  // -90° (full right)
#define SERVO_MID   1450    // 0° (center)
#define SERVO_MAX   2400    // +90° (full left)


#define SERVO_ANGLE_MIN  -90
#define SERVO_ANGLE_MAX  90

void Servo_Setup(void);
void Servo_SetAngle(int8_t angle);  // -90 to +90 degrees
void Servo_Center(void);
void Servo_Left(void);    // +90° (full left)
void Servo_Right(void);   // -90° (full right)

#endif
