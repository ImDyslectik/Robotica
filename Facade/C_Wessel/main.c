#include "ttyHandler.h"
#include "ax12.h"
#include <stdio.h>
#include "engine_family.h"
#include "../../Pipes/C/readFirst.h"
#include <wiringPi.h>

#include <pthread.h>



int main(int argc, char *argv[] ){



    wiringPiSetup();

    pinMode(1, OUTPUT);

    // engine motor1 = {23,26,true};
    // engine motor2 = {24,25,false};
    //engine_family x = {motor1, motor2}; 
    
    engine *motor1;
    motor1 = malloc(sizeof(engine));
    (*motor1).pinForward = 23;
    (*motor1).pinBackward = 26;
    (*motor1).right = true;

    engine *motor2;
    motor2 = malloc(sizeof(engine));
    (*motor2).pinForward = 24;
    (*motor2).pinBackward = 25;
    (*motor2).right = false;

    // engine_family *x;
    // x = malloc(sizeof(engine_family));
    // (*x).engineLeft = (struct engine*)motor1;
    // (*x).engineRight = (struct engine*)motor2;

    printf("MAIN\n");
    engine_family x = {motor1, motor2}; 
    move_forward(x);


    
    return 0;
}

