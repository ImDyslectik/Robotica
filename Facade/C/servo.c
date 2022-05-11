//
// Created by Jordy on 10/05/2022.
//
#include <stdio.h>
#include "servo.h"

void servo_move(servo s,int degrees){
    printf("Moving servo on pin %d to %d degrees!\n", s.pin, degrees);
}
