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

void* move_forward(void* motor_rechts, void* motor_links) 
{
    int id;
    id = 1;
    pthread_create(&id, NULL, engine_forward,(void*)motor_rechts);
    printf("werkt1\n");

    id = 2;
    pthread_create(&id, NULL, engine_forward,(void*)motor_links);
    printf("werkt2\n");

     pthread_exit(NULL);
}



void* move_backward(void* motor_rechts, void* motor_links) 
{
    int id;
    id = 1;
    pthread_create(&id, NULL, engine_backward,(void*)motor_rechts);
    printf("werkt1\n");

    id = 2;
    pthread_create(&id, NULL, engine_backward,(void*)motor_links);
    printf("werkt2\n");

     pthread_exit(NULL);
}


void* move_left(void* motor_rechts, void* motor_links) 
{
    int id;
    id = 1;
    pthread_create(&id, NULL, engine_forward,(void*)motor_rechts);
    printf("werkt1\n");

    id = 2;
    pthread_create(&id, NULL, engine_backward,(void*)motor_links);
    printf("werkt2\n");

     pthread_exit(NULL);
}


void* move_right(void* motor_rechts, void* motor_links) 
{
    int id;
    id = 1;
    pthread_create(&id, NULL, engine_backward,(void*)motor_rechts);
    printf("werkt1\n");

    id = 2;
    pthread_create(&id, NULL, engine_forward,(void*)motor_links);
    printf("werkt2\n");

     pthread_exit(NULL);
}

