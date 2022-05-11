//
// Created by Jordy on 10/05/2022.
//

#ifndef ENGINE_FAMILY_H
#define ENGINE_FAMILY_H

#include "engine.h"

typedef struct Engine_family{
    engine engine1;
    engine engine2;
    engine engine3;
    engine engine4;
} engine_family;

void move_forward(engine_family);
void move_backward(engine_family);
void move_left(engine_family);
void move_right(engine_family);

#endif //UNTITLED_ENGINE_FAMILY_H
