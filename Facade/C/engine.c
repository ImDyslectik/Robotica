//
// Created by Jordy on 10/05/2022.
//
#include <stdio.h>
#include "engine.h"

void engine_forward(engine m){
    printf("Going forward on motor with pin %d!\n", m.pin);
}

void engine_backward(engine m){
    printf("going backwards on motor with pin %d!\n", m.pin);
}
