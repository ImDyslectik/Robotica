#include <stdio.h>
#include "engine.h"


/*
* @param delay_int states the delay between increasing speed for the motors
* @param max defines the max range of the engine speed
* @param min defines the minimum range of the engine speed should always be 0
* @param range defines a variable for the for loops
*/

const int delay_Int = 200;
const int max = 50;
const int min = 0;
int range;
wiringPiSetup();

// void* engine_backward(void* m , void* goal_Speed){
//     struct Engine *my_engine = (struct Engine*)m;

//     softPwmCreate((*my_engine).pinForward,min,max);
//     softPwmCreate((*my_engine).pinBackward,min,max);
//     for (range = min; range <= max; ++range){
//         softPwmWrite((*my_engine).pinForward,min);
//         softPwmWrite((*my_engine).pinBackward,range);
//         printf("CURRENT SPEED %d \n", range);
//         delay(delay_Int);    }
//     for (range = max;range >= min;range--){
//         softPwmWrite((*my_engine).pinForward,min);
//         softPwmWrite((*my_engine).pinBackward,range);
//         printf("CURRENT SPEED %d \n", range);
//         delay(delay_Int);
//     }
// }

void* engine_forward(void* m, void* goal_Speed){
    struct Engine *my_engine = (struct Engine*)m;
    struct Speed *my_speed = (struct Speed*)goal_Speed;

    softPwmCreate((*my_engine).pinForward,min,max);
    softPwmCreate((*my_engine).pinBackward,min,max);
    printf("GOAL SPEED ENGINE %d \n", (*my_speed).goal_Speed);
    for (range = min; range <= max; ++range)
    {
        softPwmWrite((*my_engine).pinForward,range);
        softPwmWrite((*my_engine).pinBackward,min);
        printf("CURRENT SPEED %d \n", range);
        printf("GOAL SPEED COMPLETE %d \n", (*my_speed).goal_Speed);
//        printf("RUN: pinForward %d pinBackward %d right %d \n", (*my_engine).pinForward, (*my_engine).pinBackward, (*my_engine).right); 
        delay(delay_Int);    
    }
        delay(15000);
    for (range=max;range > min;range--){
        softPwmWrite((*my_engine).pinForward,range);
        softPwmWrite((*my_engine).pinBackward,min);
        printf("CURRENT SPEED %d \n", range);
        printf("GOAL SPEED COMPLETE %d \n", (*my_speed).goal_Speed);
//        printf("RUN: pinForward %d pinBackward %d right %d \n", (*my_engine).pinForward, (*my_engine).pinBackward, (*my_engine).right); 
        delay(delay_Int);
    }
    return;
}

