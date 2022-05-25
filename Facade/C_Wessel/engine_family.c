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
    Pairs *pair;
    pair = malloc(sizeof(Pairs));
    (*pair).i = 1;
    (*pair).j = 2;

    Pairs *pair2;
    pair2 = malloc(sizeof(Pairs));
    (*pair2).i = 3;
    (*pair2).j = 4;
    //printf("werkt nog\n");
    //pthread_create(&id, NULL,printer, (void*) pair);
    

    id = 2;
    //pthread_create(&id, NULL,printer, (void*) pair2);
    //printf("werkt1\n");
   
    id = 3;

    pthread_create(&id, NULL, engine_forward,(void*) motor3);
    printf("werkt3\n");

    id = 4;

    pthread_create(&id, NULL, engine_forward,(void*) motor4);
    printf("werkt4\n");

     pthread_exit(NULL);
}




