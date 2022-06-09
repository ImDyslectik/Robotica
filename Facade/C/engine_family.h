#ifndef ENGINE_FAMILY_H
#define ENGINE_FAMILY_H
#include "engine.h"

typedef struct Engine_family{
    engine engineLeft;
    engine engineRight;
} engine_family;

void move_forward(void* motor_rechts, void* motor_links, void*);
void move_backward(void* motor_rechts, void* motor_links, void*);
void move_left(void* motor_rechts, void* motor_links, void*);
void move_right(void* motor_rechts, void* motor_links, void*);

#endif //UNTITLED_ENGINE_FAMILY_H
