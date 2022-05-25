#ifndef MOTOR_H
#define MOTOR_H
#include <stdbool.h>

typedef struct Engine {
    int pinForward;
    int pinBackward;
    bool right;
} engine;

typedef struct Pairs {
    long i,j;
}Pairs;
void* printer(void*);
void* engine_forward(void*);

void* engine_backward(void*);

#endif //MOTOR_H
