#ifndef UART_H
#define UART_H

#include "main.h"
#include "pwm.h"

#define SPEED_MAX    800

#define SPEED_MAX_A  625
#define SPEED_MAX_B  765

#define TURN_FAST    700
#define TURN_SLOW    200

typedef enum {
    STATE_STOP    = 0,
    STATE_FORWARD = 1,
    STATE_LEFT    = 2,
    STATE_RIGHT   = 3
} MotorState;

typedef enum {
    CMD_NONE    = 0,
    CMD_FORWARD = 1,
    CMD_LEFT    = 2,
    CMD_RIGHT   = 3,
    CMD_STOP    = 4
} MotorCommand;

typedef enum {
    TURN_HINT_NONE = 0,
    TURN_HINT_LEFT,
    TURN_HINT_RIGHT
} TurnHint;

extern volatile TurnHint turnHint;
extern MotorState currentState;
extern volatile uint8_t pendingCommand;
extern volatile int32_t currentSpeedA;
extern volatile int32_t currentSpeedB;
extern volatile int32_t targetSpeedA;
extern volatile int32_t targetSpeedB;

void UART_Setup(void);
void Process_UART_Command(void);
void Motor_Update(void);
void SetForwardPins(void);
void ClearDirectionPins(void);
void Motor_SetTarget(int32_t a, int32_t b);
void Motor_SetImmediate(int32_t a, int32_t b);

#endif
