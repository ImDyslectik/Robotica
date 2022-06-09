#include <stdio.h>
#include "engine.h"


/*
* @param delay_int states the delay between increasing speed for the motors
* @param max defines the max range of the engine speed
* @param min defines the minimum range of the engine speed should always be 0
* @param range defines a variable for the for loops
*/

const int delay_Int = 200;
const int max = 50;
const int min = 0;
int range;
wiringPiSetup();

void* engine_run(void* m)
{
    struct Engine *my_engine = (struct Engine*)m;
    int thread_id = (*my_engine).threadid;
    softPwmCreate((*my_engine).pinForward,min,max);
    softPwmCreate((*my_engine).pinBackward,min,max);
    (*my_engine).current_Speed = (*my_engine).current_Speed + (*my_engine).update_Speed;
    if((*my_engine).forward == true && (*my_engine).backward == false)
    {
        (*my_engine).current_Goal = (*my_engine).current_Goal - ((*my_engine).update_Speed * 10);

        //Motoren laten bewegen
        softPwmWrite((*my_engine).pinForward,(*my_engine).current_Speed);
        softPwmWrite((*my_engine).pinBackward,min);
    }
    if((*my_engine).backward == true && (*my_engine).forward == false)
    {
        (*my_engine).current_Goal = (*my_engine).current_Goal + ((*my_engine).update_Speed * 10);

    //Motoren laten bewegen
    softPwmWrite((*my_engine).pinForward,min);
    softPwmWrite((*my_engine).pinBackward,(*my_engine).current_Speed);
    }
    delay(delay_Int);
}

void* engine_forward(void* m)
{
    
    struct Engine *my_engine = (struct Engine*)m;
    int thread_id = (*my_engine).threadid;
    softPwmCreate((*my_engine).pinForward,min,max);
    softPwmCreate((*my_engine).pinBackward,min,max);
    printf("RUN: pinForward %d pinBackward %d right %d \n", (*my_engine).pinForward, (*my_engine).pinBackward, (*my_engine).right); 
    printf("CURRENT SPEED %d GOAL SPEED %d\n", (*my_engine).current_Speed, (*my_engine).goal_Speed);
    printf("switchable %d forward %d backward %d \n", (*my_engine).switchable, (*my_engine).forward, (*my_engine).backward);
    //stil staan
    if(((*my_engine).goal_Speed > 500 && (*my_engine).goal_Speed < 530) && ((*my_engine).current_Goal > 490 && (*my_engine).current_Goal < 540
    || ((*my_engine).goal_Speed > 500 && (*my_engine).goal_Speed < 530) && (*my_engine).emergency_break == true))
    {   
        (*my_engine).current_Speed = 0;
        (*my_engine).switchable = true;
        (*my_engine).forward = false;
        (*my_engine).backward = false;
        //Motoren laten bewegen
        softPwmWrite((*my_engine).pinForward,(*my_engine).current_Speed);
        softPwmWrite((*my_engine).pinBackward,min);
        delay(delay_Int);
        return;
    }

    //Vooruit versnellen met 1
if((*my_engine).current_Goal > (*my_engine).goal_Speed - 10 && (*my_engine).current_Goal < (*my_engine).goal_Speed + 100 && ((*my_engine).current_Speed + 1) < 51 && (*my_engine).switchable == true
    || (*my_engine).current_Goal > (*my_engine).goal_Speed - 10 && (*my_engine).current_Goal < (*my_engine).goal_Speed + 100 &&  ((*my_engine).current_Speed + 1) < 51 && (*my_engine).forward == true)
    {
        (*my_engine).backward = false; 
        (*my_engine).switchable = false;
        (*my_engine).forward = true;
        (*my_engine).update_Speed = 1;

        engine_run(my_engine);  
        return;
    }

    //Vooruit vertragen met 1
    if((*my_engine).current_Goal < (*my_engine).goal_Speed - 10 && (*my_engine).current_Goal > (*my_engine).goal_Speed - 100 && ((*my_engine).current_Speed - 1) > (-1) && (*my_engine).switchable == true
    || (*my_engine).current_Goal < (*my_engine).goal_Speed - 10 && (*my_engine).current_Goal > (*my_engine).goal_Speed - 100 && ((*my_engine).current_Speed - 1) > (-1) && (*my_engine).forward == true)
    {
        (*my_engine).backward = false; 
        (*my_engine).switchable = false;
        (*my_engine).forward = true;
        (*my_engine).update_Speed = -1;

        engine_run(my_engine);  
        return;
    }
           
    //Achteruit versnellen met 1
    if((*my_engine).current_Goal < (*my_engine).goal_Speed + 10 && (*my_engine).current_Goal > (*my_engine).goal_Speed - 100 && ((*my_engine).current_Speed + 1) < 51 && (*my_engine).switchable == true
    || (*my_engine).current_Goal < (*my_engine).goal_Speed + 10 && (*my_engine).current_Goal > (*my_engine).goal_Speed - 100 &&  ((*my_engine).current_Speed + 1) < 51 && (*my_engine).backward == true)
    {
        (*my_engine).backward = true; 
        (*my_engine).switchable = false;
        (*my_engine).forward = false;
        (*my_engine).update_Speed = 1;

        engine_run(my_engine);  
        return;
    }

    //Achteruit vertragen met 1
    if((*my_engine).current_Goal > (*my_engine).goal_Speed + 10 && (*my_engine).current_Goal < (*my_engine).goal_Speed + 100 && ((*my_engine).current_Speed - 1) > (-1) && (*my_engine).switchable == true
    || (*my_engine).current_Goal > (*my_engine).goal_Speed + 10 && (*my_engine).current_Goal < (*my_engine).goal_Speed + 100 && ((*my_engine).current_Speed - 1) > (-1) && (*my_engine).backward == true )
    {
        (*my_engine).backward = true; 
        (*my_engine).switchable = false;
        (*my_engine).forward = false;
        (*my_engine).update_Speed = -1;

        engine_run(my_engine);  
        return;
    }


    //Vooruit versnellen met 10
    if((*my_engine).current_Goal > (*my_engine).goal_Speed - 100 && ((*my_engine).current_Speed + 10) < 51 && (*my_engine).switchable == true
    || (*my_engine).current_Goal > (*my_engine).goal_Speed - 100 && ((*my_engine).current_Speed + 10) < 51 && (*my_engine).forward == true)
    {
        (*my_engine).backward = false; 
        (*my_engine).switchable = false;
        (*my_engine).forward = true;
        (*my_engine).update_Speed = 10;

        engine_run(my_engine);  
        return;
    }

    //Vooruit vertragen met 10
    if((*my_engine).current_Goal < (*my_engine).goal_Speed - 100 && ((*my_engine).current_Speed - 10) > (-1) && (*my_engine).switchable == true
    || (*my_engine).current_Goal < (*my_engine).goal_Speed - 100 && ((*my_engine).current_Speed - 10) > (-1) && (*my_engine).forward == true)
    {
        (*my_engine).backward = false; 
        (*my_engine).switchable = false;
        (*my_engine).forward = true;
        (*my_engine).update_Speed = -10;

        engine_run(my_engine);  
        return;
    }
           
    //Achteruit versnellen met 10
    if((*my_engine).current_Goal < (*my_engine).goal_Speed + 100 && ((*my_engine).current_Speed + 10) < 51 && (*my_engine).switchable == true
    || (*my_engine).current_Goal < (*my_engine).goal_Speed + 100 && ((*my_engine).current_Speed + 10) < 51 && (*my_engine).backward == true)
    {
        (*my_engine).backward = true; 
        (*my_engine).switchable = false;
        (*my_engine).forward = false;
        (*my_engine).update_Speed = 10;

        engine_run(my_engine);  
        return;
    }

    //Achteruit vertragen met 10
    if((*my_engine).current_Goal > (*my_engine).goal_Speed + 100 && ((*my_engine).current_Speed - 10) > (-1) && (*my_engine).switchable == true
    || (*my_engine).current_Goal > (*my_engine).goal_Speed + 100 && ((*my_engine).current_Speed - 10) > (-1) && (*my_engine).backward == true )
    {
        (*my_engine).backward = true; 
        (*my_engine).switchable = false;
        (*my_engine).forward = false;
        (*my_engine).update_Speed = -10;

        engine_run(my_engine);  
        return;
    }



printf("OUT OF SCOPE \n");
delay(delay_Int);
return;
}
