#ifndef MOTOR_H
#define MOTOR_H
#include <stdbool.h>

typedef struct Engine {
    int pinForward;
    int pinBackward;
    bool right;
    int goal_Speed;
    int current_Goal;
    int current_Speed;
    int update_Speed;
    int threadid;
    bool switchable;
    bool forward;
    bool backward;
    bool emergency_break;
} engine;

// typedef struct Speed {
//     int goal_Speed;
// } speed;


void* engine_forward(void* m);
void* engine_backward(void* m);

#endif //MOTOR_H
