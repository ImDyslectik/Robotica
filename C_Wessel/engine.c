#include <stdio.h>
#include "engine.h"
#include <pthread.h>

/*
* @param delay_int states the delay between increasing speed for the motors
* @param max defines the max range of the engine speed
* @param min defines the minimum range of the engine speed should always be 0
* @param range defines a variable for the for loops
*/

const int delay_Int = 1500;
const int max = 5;
const int min = 0;
int range;
wiringPiSetup();

void* engine_backward(void* m)
{
    struct Engine *my_engine = (struct Engine*)m;
    printf("Thread %d \n", (*my_engine).pinForward); 

    softPwmCreate((*my_engine).pinForward,min,max);
    softPwmCreate((*my_engine).pinBackward,min,max);
    int i = 0;
    while(i < 3)
    {
    for (range = min; range <= max; ++range)
    {
        softPwmWrite((*my_engine).pinForward,min);
        softPwmWrite((*my_engine).pinBackward,range);
        delay(delay_Int);    }
    for (range = max;range >= min;range--)
    {
        softPwmWrite((*my_engine).pinForward,min);
        softPwmWrite((*my_engine).pinBackward,range);
        delay(delay_Int);
    }
    i++;
    }
}

void* engine_forward(void* m)
{
    struct Engine *my_engine = (struct Engine*)m;
    printf("pinForward %d \n", (*my_engine).pinForward); 
    printf("pinBackward %d \n", (*my_engine).pinBackward); 
    printf("right %d \n", (*my_engine).right); 

    softPwmCreate((*my_engine).pinForward,min,max);
    softPwmCreate((*my_engine).pinBackward,min,max);
    int i = 0;
    while(i < 3){
    for (range = min; range <= max; ++range)
    {
        softPwmWrite((*my_engine).pinForward,range);
        softPwmWrite((*my_engine).pinBackward,min);
        delay(delay_Int); 
       // printf("RUN: pinForward %d pinBackward %d right %d \n", (*my_engine).pinForward, (*my_engine).pinBackward, (*my_engine).right);    
    }
    for (range=max;range > min;range--)
    {
        softPwmWrite((*my_engine).pinForward,range);
        softPwmWrite((*my_engine).pinBackward,min);
        delay(delay_Int);
        //printf("RUN: pinForward %d pinBackward %d right %d \n", (*my_engine).pinForward, (*my_engine).pinBackward, (*my_engine).right); 
        }
        i++;
    }
    return;
}
