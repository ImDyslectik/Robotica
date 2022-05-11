//
// Created by Jordy on 10/05/2022.
//

#ifndef MOTOR_H
#define MOTOR_H

#include <stdbool.h>

typedef struct Engine {
    int pin;
    bool right;
    bool front;
} engine;

void engine_forward(engine);

void engine_backward(engine);

#endif //MOTOR_H
