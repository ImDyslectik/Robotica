#ifndef MOTOR_H
#define MOTOR_H

#include <stdbool.h>

typedef struct Engine {
    int pinForward;
    int pinBackward;
    bool right;
} engine;

void engine_forward(engine);

void engine_backward(engine);

#endif //MOTOR_H
