//
// Created by Jordy on 10/05/2022.
//

#include "engine.h"
#include "engine_family.h"

/**
 * M1 ---- M2
 *
 * M3 ---- M4
 */

void move_forward(engine_family f){
    engine_forward(f.engine1);
    engine_forward(f.engine2);
    engine_forward(f.engine3);
    engine_forward(f.engine4);
}
void move_backward(engine_family f){
    engine_backward(f.engine1);
    engine_backward(f.engine2);
    engine_backward(f.engine3);
    engine_backward(f.engine4);
}
void move_left(engine_family f){
    engine_backward(f.engine1);
    engine_forward(f.engine2);
    engine_backward(f.engine3);
    engine_forward(f.engine4);
}
void move_right(engine_family f){
    engine_forward(f.engine1);
    engine_backward(f.engine2);
    engine_forward(f.engine3);
    engine_backward(f.engine4);
}
