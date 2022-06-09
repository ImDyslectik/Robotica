#ifndef ENGINE_FAMILY_H
#define ENGINE_FAMILY_H
#include "engine.h"

typedef struct Engine_family{
    engine engineLeft;
    engine engineRight;
} engine_family;

void move_forward(engine_family, void* );
void move_backward(engine_family);
void move_left(engine_family);
void move_right(engine_family);

#endif //UNTITLED_ENGINE_FAMILY_H
