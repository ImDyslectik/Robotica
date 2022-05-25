#include <stdio.h>
#include "engine.h"
#include <pthread>

/*
* @param delay_int states the delay between increasing speed for the motors
* @param max defines the max range of the engine speed
* @param min defines the minimum range of the engine speed should always be 0
* @param range defines a variable for the for loops
*/

const int delay_Int = 700;
const int max = 5;
const int min = 0;
int range;
wiringPiSetup();

void* engine_backward(void* m){
    struct Engine *my_engine = (struct Engine*)m;
    printf("Thread %d \n", (*my_engine).pinForward); 

    softPwmCreate((*my_engine).pinForward,min,max);
    softPwmCreate((*my_engine).pinBackward,min,max);
    for (range = min; range <= max; ++range){
        softPwmWrite((*my_engine).pinForward,min);
        softPwmWrite((*my_engine).pinBackward,range);
        delay(delay_Int);    }
    for (range = max;range >= min;range--){
        softPwmWrite((*my_engine).pinForward,min);
        softPwmWrite((*my_engine).pinBackward,range);
        delay(delay_Int);
    }
}

void* engine_forward(void* m){
    struct Engine *my_engine = (struct Engine*)m;
    printf("Thread %d \n", (*my_engine).pinForward); 

    softPwmCreate((*my_engine).pinForward,min,max);
    softPwmCreate((*my_engine).pinBackward,min,max);
    for (range = min; range <= max; ++range){
        softPwmWrite((*my_engine).pinForward,range);
        softPwmWrite((*my_engine).pinBackward,min);
        delay(delay_Int);    }
    for (range=max;range > min;range--){
        softPwmWrite((*my_engine).pinForward,range);
        softPwmWrite((*my_engine).pinBackward,min);
        delay(delay_Int);
    }

    pthread_join(min, NULL);
    pthread_join(1, NULL);
    return;
}
