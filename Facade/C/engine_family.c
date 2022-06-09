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

void move_forward(void* motor_rechts, void* motor_links, void* goal_Speed){
    int id;
    id = 1;
    struct Engine *my_engine = (struct Engine*)motor_links;
    //struct Speed *my_speed = (struct Speed*)goal_Speed;
    //printf("GOAL SPEED Family %d \n", (*my_speed).goal_Speed);
    //printf("Motor Links %d \n", (*my_engine).pinForward);
    pthread_create(&id, NULL, engine_forward,((void*) (void*)(motor_rechts, goal_Speed)));

    delay(1);
    //printf("first thread completed %d \n", (*my_speed).goal_Speed);
    id = 2;
    pthread_create(&id, NULL, engine_forward,((void*) (void*)motor_links, goal_Speed));

    pthread_exit(NULL);
}

// void move_backward(void* motor_rechts, void* motor_links, void* goal_Speed){
//     int id;
//     id = 1;
//     pthread_create(&id, NULL, engine_forward,(void*, void*)motor_rechts, goal_Speed);

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
