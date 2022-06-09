#include <stdio.h>
#include "engine.h"
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
void* engine_backward(void* m){
    //printf("going backwards on motor with pin\n");
}

void* engine_forward(void* m){
    const int delay_Int = 5000;
    struct Engine *my_engine = (struct Engine*)m;
    softPwmCreate((*my_engine).pinForward,0,5);
    softPwmCreate((*my_engine).pinBackward,0,5);

    wiringPiSetup();

    while (1) {
        softPwmWrite((*my_engine).pinForward,0);
        softPwmWrite((*my_engine).pinBackward,0);
        delay(delay_Int);
        printf("RUN: pinForward %d pinBackward %d right %d \n", (*my_engine).pinForward, (*my_engine).pinBackward, (*my_engine).right); 
        softPwmWrite((*my_engine).pinForward,2);
        softPwmWrite((*my_engine).pinBackward,0);
        delay(delay_Int);
        printf("RUN: pinForward %d pinBackward %d right %d \n", (*my_engine).pinForward, (*my_engine).pinBackward, (*my_engine).right); 
        softPwmWrite((*my_engine).pinForward,5);
        softPwmWrite((*my_engine).pinBackward,0);
        delay(delay_Int);
        printf("RUN: pinForward %d pinBackward %d right %d \n", (*my_engine).pinForward, (*my_engine).pinBackward, (*my_engine).right); 
        softPwmWrite((*my_engine).pinForward,2);
        softPwmWrite((*my_engine).pinBackward,0);
        delay(delay_Int);
        printf("RUN: pinForward %d pinBackward %d right %d \n", (*my_engine).pinForward, (*my_engine).pinBackward, (*my_engine).right); 
    }

    return;
}
