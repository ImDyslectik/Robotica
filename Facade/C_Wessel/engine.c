#include <stdio.h>
#include "engine.h"
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
void* engine_backward(void* m){
    printf("going backwards on motor with pin\n");
}

void* printer(void* pair){
    sleep(2);
    //struct Pairs *my_pair = (struct Pairs*)pair;
    //printf("Thread %d, %d \n", (*my_pair).i, (*my_pair).j);
    return NULL;
}


void* engine_forward(void* m){
    const int delay_Int = 5000;
    struct Engine *my_engine = (struct Engine*)m;
    printf("pinFordward %d \n", (*my_engine).pinForward); 
    printf("pinBackward %d \n", (*my_engine).pinBackward); 
    printf("right %d \n", (*my_engine).right); 
    softPwmCreate((*my_engine).pinForward,0,5);
    softPwmCreate((*my_engine).pinBackward,0,5);

    wiringPiSetup();

    while (1) {
        softPwmWrite((*my_engine).pinForward,0);
        softPwmWrite((*my_engine).pinBackward,0);
        delay(delay_Int);
        softPwmWrite((*my_engine).pinForward,2);
        softPwmWrite((*my_engine).pinBackward,0);
        delay(delay_Int);
        softPwmWrite((*my_engine).pinForward,5);
        softPwmWrite((*my_engine).pinBackward,0);
        delay(delay_Int);
        softPwmWrite((*my_engine).pinForward,2);
        softPwmWrite((*my_engine).pinBackward,0);
        delay(delay_Int);
    }

    pthread_join(0, NULL);
    pthread_join(1, NULL);
    return;
}
