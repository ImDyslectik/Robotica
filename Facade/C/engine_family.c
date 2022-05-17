#include "engine.h"
#include "engine_family.h"

/**
 * M1 ---- M2
 *
 * M1 ---- M2
 */

void move_forward(engine_family f){
    engine_forward(f.engineLeft);
    engine_forward(f.engineRight);
}
void move_backward(engine_family f){
    engine_backward(f.engineLeft);
    engine_backward(f.engineRight);
}
void move_left(engine_family f){
    engine_backward(f.engineLeft);
    engine_forward(f.engineRight);
}
void move_right(engine_family f){
    engine_forward(f.engineLeft);
    engine_backward(f.engineRight);
}
