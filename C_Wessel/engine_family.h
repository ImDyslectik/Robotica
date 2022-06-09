#ifndef ENGINE_FAMILY_H
#define ENGINE_FAMILY_H
#include "engine.h"

typedef struct Engine_family{
    engine engineLeft;
    engine engineRight;
} engine_family;

void* move_forward(void*, void*);
void* move_backward(void*, void*);
void* move_left(void*, void*);
void* move_right(void*, void*);

#endif //UNTITLED_ENGINE_FAMILY_H
