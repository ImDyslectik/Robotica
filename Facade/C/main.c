#include "ttyHandler.h"
#include "ax12.h"
#include <stdio.h>
#include "hc.h"
#include "engine_family.h"
#include "../../Pipes/C/readFirst.h"
#include <wiringPi.h>
#include <pthread.h>

int main2(){
    wiringPiSetup();
    pinMode(18, OUTPUT);
    int goal_Speed_Input = 515;
    speed *speed1;
        speed1 = malloc(sizeof(speed1));
        (*speed1).goal_Speed = goal_Speed_Input;

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

        ax12 s = {18, true};
        ax12Speed(s, 100);

        delay(2000);
        ax12Speed(s, 0);
        printf("GOAL SPEED MAIN %d \n", (*speed1).goal_Speed);
        move_forward(motor1,motor2, speed1);
}

/*
* main for testing the engine direction and servo control based on
* air quality detection based on potmeter and vision
*/
int main(int argc, char *argv[] ){
    wiringPiSetup();
    int engine_command[4];
    readSetup(engine_command);
    //sensor(engine_command);
    pinMode(1, OUTPUT);

    /*
    * The first argument is a pointer to thread_ids which is set by this function.
    * The second argument specifies attributes. If the value is NULL, then default attributes shall be used.
    * The third argument is name of function to be executed for the thread to be created, in our case reading()
    * The fourth argument is used to pass arguments to the function, in our case a pointer to engine_command array.
    */
    int Forward = 900;
    int Backward = 0;
    int thread_ids = 3;
    pthread_create(&thread_ids,NULL,reading,(int*) engine_command);
    int thread_idss = 4;
    pthread_create(&thread_ids,NULL,sensor,(int*) engine_command);

    while(1){
        engine motor1 = {23,26,true};
        engine motor2 = {24,25,false};
        engine_family x = {motor1, motor2}; 
    
        if (engine_command[0] == Forward && engine_command[1] == Forward){
    	    //move_forward(x,1);
            printf("forward \n");
        }
        if (engine_command[0] == Backward && engine_command[1] == Backward){
            //printf("back \n");
    	    //move_backward(x);
        }
        if (engine_command[0] == Backward && engine_command[1] == Forward){
            printf("left \n");
    	    //move_left(x);
        }
        if (engine_command[0] == Forward && engine_command[1] == Backward){
            printf("right \n");
        	//move_right(x);
        }
        if(engine_command[2] != 1){
        ax12 s = {18, true};
        if (engine_command[2] == 0)
        {
            // printf("print niet pls %d\n", engine_command[2]);
            // draai naar rechts
            ax12Speed(s, 50);
        }
        if (engine_command[2] == 2)
        {
            // draai naar links
            ax12Speed(s, -50);
        }
        if (engine_command[2] == 1)
        {
            // stop met draaien
            ax12Speed(s, 0);
        }
        }
        if (engine_command[3] == 1){
            badAir();
        }
    }
    return 0;
}

void badAir(){
        int engine_command[4];
        if (engine_command[3] == 1){
            
            ax12 s1 = {2, false};
            ax12 s2 = {4, false};
            ax12Speed(s1, 20);
            ax12Speed(s2, 20);
            sleep(1);
            //servo 1 omhoog
            ax12Move(s1, 150+105);
            //servo 2 omlaag
            ax12Move(s2, 150-105);
            sleep(1);
            //servo 1 omlaag
            ax12Move(s1, 150+20);
            //servo 2 omhoog
            ax12Move(s2, 150-20);
            sleep(1);
            printf("smerige lucht \n");

        }
}