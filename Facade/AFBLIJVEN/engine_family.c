#include "engine.h"
#include "engine_family.h"
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <stdio.h>
/**
 * M1 ---- M2
 *
 * M1 ---- M2
 */

void move_forward(void* motor_rechts, void* motor_links){

    struct Engine *my_engine_links = (struct Engine*)motor_links;
    struct Engine *my_engine_rechts = (struct Engine*)motor_rechts;
    int thread_ID_Links = (*my_engine_links).threadid;
    int thread_ID_Rechts = (*my_engine_rechts).threadid;
    //printf("GOAL SPEED Family %d \n", (*my_engine_links).goal_Speed);
    //printf("RUN: pinForward %d pinBackward %d right %d \n", (*my_engine_links).pinForward, (*my_engine).pinBackward, (*my_engine).right); 
    
    pthread_create(&thread_ID_Rechts, NULL, engine_forward,(void*) motor_rechts);
    delay(10);
    pthread_create(&thread_ID_Links, NULL, engine_forward,(void*)motor_links);
   
    pthread_join(thread_ID_Rechts, NULL);
    pthread_join(thread_ID_Links, NULL);
    delay(20);
    return;
}

// void move_backward(void* motor_rechts, void* motor_links){
//     int id;
//     id = 1;
//     pthread_create(&id, NULL, engine_forward,(void*)motor_rechts);

//     delay(1);

//     id = 2;
//     pthread_create(&id, NULL, engine_forward,(void*, void*)motor_links, goal_Speed);

//     pthread_exit(NULL);
// }
// void move_left(void* motor_rechts, void* motor_links, void* goal_Speed){
//     int id;
//     id = 1;
//     pthread_create(&id, NULL, engine_forward,(void*, void*)motor_rechts, goal_Speed);

//     delay(1);

//     id = 2;
//     pthread_create(&id, NULL, engine_forward,(void*, void*)motor_links, goal_Speed);

//     pthread_exit(NULL);
// }
// void move_right(void* motor_rechts, void* motor_links, goal_Speed){
//     int id;
//     id = 1;
//     pthread_create(&id, NULL, engine_forward,(void*, void*)motor_rechts, goal_Speed);

//     delay(1);

//     id = 2;
//     pthread_create(&id, NULL, engine_forward,(void*, void*)motor_links, goal_Speed);

//     pthread_exit(NULL);
// }
