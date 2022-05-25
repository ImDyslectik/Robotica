#include "engine.h"
#include <softPwm.h>
#include <pthread.h>

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

void engine_backward(engine m){
    
    softPwmCreate(m.pinForward,min,max);
    softPwmCreate(m.pinBackward,min,max);
    for (range = min; range <= max; ++range){
        softPwmWrite(m.pinForward,min);
        softPwmWrite(m.pinBackward,range);
        delay(delay_Int);    }
    for (range = max;range >= min;range--){
        softPwmWrite(m.pinForward,min);
        softPwmWrite(m.pinBackward,range);
        delay(delay_Int);
    }
}

void engine_forward(engine m){
    softPwmCreate(m.pinForward,min,max);
    softPwmCreate(m.pinBackward,min,max);
    for (range = min; range <= max; ++range){
        softPwmWrite(m.pinForward,range);
        softPwmWrite(m.pinBackward,min);
        delay(delay_Int);    }
    for (range=max;range > min;range--){
        softPwmWrite(m.pinForward,range);
        softPwmWrite(m.pinBackward,min);
        delay(delay_Int);
    }

    pthread_join(min, NULL);
    pthread_join(1, NULL);
    return;
}
