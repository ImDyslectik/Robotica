#include "ttyHandler.h"
#include "ax12.h"
#include <stdio.h>
#include "engine_family.h"
#include "../../Pipes/C/readFirst.h"
#include <wiringPi.h>
#include <pthread.h>


int main(){
    wiringPiSetup();
    pinMode(18, OUTPUT);
    int state = 0;
    int goal_Speed_Input1 = 515;
    int goal_Speed_Input2 = 515;

    int engine_command[4];
    readSetup(engine_command);

    int thread_ids = 3;
    pthread_create(&thread_ids,NULL,reading,(int*) engine_command);

     engine *motor1;
        motor1 = malloc(sizeof(engine));
        (*motor1).pinForward = 23;
        (*motor1).pinBackward = 29;
        (*motor1).right = true;
        (*motor1).goal_Speed = goal_Speed_Input1;
        (*motor1).current_Speed = 0;
        (*motor1).current_Goal = 515;
        (*motor1).threadid = 1;
        (*motor1).switchable = true;
        (*motor1).forward = false;
        (*motor1).backward = false;


        engine *motor2;
        motor2 = malloc(sizeof(engine));
        (*motor2).pinForward = 24;
        (*motor2).pinBackward = 25;
        (*motor2).right = false;
        (*motor2).goal_Speed = goal_Speed_Input2;
        (*motor2).current_Speed = 0;
        (*motor2).current_Goal = 515;
        (*motor2).threadid = 2;
        (*motor2).switchable = true;
        (*motor2).forward = false;
        (*motor2).backward = false;

    while(true)
    {
        //ax12 s = {18, true};
        //ax12Speed(s, 100);
        //ax12Speed(s, 0);
        //printf("BEGIN LOOP IN MAIN \n");

        //stel hier je gewilde stand in P.S moet nog gekoppeld worden aan de controller
        state = 1;

        //stand is manual
        if(state == 0)
        {
            printf("LOOP 10\n");
            for(int i = 0; i < 5; i++)
            {
                printf("LOOP 20\n");
                (*motor1).goal_Speed = (*motor1).goal_Speed - 100;
                (*motor2).goal_Speed = (*motor2).goal_Speed + 100;
                move_forward(motor1,motor2);   
                delay(100);
            }
            delay(5000);
            for(int i = 0; i < 5; i++)
            {
                printf("LOOP 30\n");
                (*motor1).goal_Speed = (*motor1).goal_Speed + 100;
                (*motor2).goal_Speed = (*motor2).goal_Speed - 100;
                move_forward(motor1,motor2);   
                delay(100);
            } 
            (*motor1).goal_Speed = 515;
            (*motor2).goal_Speed = 515;
            (*motor1).current_Goal = 515;
            (*motor2).current_Goal = 515;
            move_forward(motor1,motor2); 
            delay(5000);
            for(int i = 0; i < 5; i++)
            {
                printf("LOOP 40\n");
                (*motor1).goal_Speed = (*motor1).goal_Speed - 100;
                (*motor2).goal_Speed = (*motor2).goal_Speed + 100;
                move_forward(motor1,motor2);   
                delay(100);
            }  
            delay(5000);
            for(int i = 0; i < 5; i++)
            {
                printf("LOOP 50\n");
                (*motor1).goal_Speed = (*motor1).goal_Speed + 100;
                (*motor2).goal_Speed = (*motor2).goal_Speed - 100;
                move_forward(motor1,motor2);   
                delay(100);
            }  
            (*motor1).goal_Speed = 515;
            (*motor2).goal_Speed = 515;
            (*motor1).current_Goal = 515;
            (*motor2).current_Goal = 515;
            move_forward(motor1,motor2);

            delay(5000);
        }
        
        //stand 1 is autonoom
        if(state == 1)
        {
            goal_Speed_Input1 = engine_command[0];
            goal_Speed_Input2 = engine_command[1];
            printf("INPUT1 %d INPUT2 %d \n", goal_Speed_Input1, goal_Speed_Input2);
            if(goal_Speed_Input1 == 9999)
            {
                (*motor1).goal_Speed = 515;
                (*motor1).emergency_break = true; 
            }
            else
            {
                (*motor1).goal_Speed = goal_Speed_Input1;
            }
            if(goal_Speed_Input2 == 9999)
            {
                (*motor2).goal_Speed = 515;
                (*motor2).emergency_break = true;
            }
            else
            {
                (*motor2).goal_Speed = goal_Speed_Input2;
            }

            move_forward(motor1,motor2);
            delay(100);
            (*motor1).emergency_break = false; 
            (*motor2).emergency_break = false;
            delay(100);
        }

        //stand 2 is dansen
        if(state == 2)
        {
            printf("DANCE!!!!!");
        }


        


        
    }
}
