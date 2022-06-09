#include "engine.h"
#include "engine_family.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
/**
 * M1 ---- M2
 *
 * M1 ---- M2
 */



void move_forward(engine_family f) 
{

    engine *motor3;
    motor3 = malloc(sizeof(engine));
    (*motor3).pinForward = 23;
    (*motor3).pinBackward = 26;
    (*motor3).right = true;

    engine *motor4;
    motor4 = malloc(sizeof(engine));
    (*motor4).pinForward = 24;
    (*motor4).pinBackward = 25;
    (*motor4).right = false;

    int id = 1;
    printf("werkt\n");
    pthread_create(&id, NULL, engine_forward,(void*) motor3);
    
    delay(1);

    id = 2;
    pthread_create(&id, NULL, engine_forward,(void*) motor4);


    pthread_exit(NULL);
}




