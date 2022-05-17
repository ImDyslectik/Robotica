#include <stdio.h>
#include "engine.h"
#include <wiringPi.h>
#include <softPwm.h>

void engine_backward(engine m){
    printf("going backwards on motor with pin %d!\n", m.pin);
}

void engine_forward(engine m){
    const int delay = 5000;

    softPwmCreate(m.pinForward,0,5);
    softPwmCreate(m.pinBackward,0,5);

    wiringPiSetup();

    pinMode(led, OUTPUT);

    while (1) {
        softPwmWrite(m.pinForward,0);
        softPwmWrite(m.pinBackward,0);
        delay(delay);
        softPwmWrite(m.pinForward,2);
        softPwmWrite(m.pinBackward,0);
        delay(delay);
        softPwmWrite(m.pinForward,5);
        softPwmWrite(m.pinBackward,0);
        delay(delay);
        softPwmWrite(m.pinForward,2);
        softPwmWrite(m.pinBackward,0);
        delay(delay);
    }
    return 0;
}