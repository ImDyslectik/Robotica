#include "ttyHandler.h"
#include "ax12.h"
#include <stdio.h>
#include "engine_family.h"
#include "../../Pipes/C/readFirst.h"
#include <wiringPi.h>

#include <pthread.h>

int main(int argc, char *argv[] ){
    // //set up wiringpi stuff, and set the gpio pin to output
    wiringPiSetup();

    pinMode(1, OUTPUT);
    int engine_command[2];
    //readSetup(engine_command);

    while(1){
        //reading(engine_command);
        printf("%d \n",engine_command[0]);
        printf("%d \n",engine_command[1]);

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
    
        if (engine_command[0] == 1 && engine_command[1] == 1){
            printf("forward \n");
    	    move_forward(motor1,motor2);
        }
        if (engine_command[0] == 0 && engine_command[1] == 0){
            printf("back \n");
    	    move_backward(motor1,motor2);
        }
        if (engine_command[0] == 0 && engine_command[1] == 1){
            printf("left \n");
    	    move_left(motor1,motor2);
        }
        if (engine_command[0] == 1 && engine_command[1] == 0){
            printf("right \n");
        	move_right(motor1,motor2);
        };
    }
    return 0;
}


//     wiringPiSetup();

//     pinMode(1, OUTPUT);

    
    


//     printf("MAIN\n");

//     move_left(motor1, motor2);


    
//     return 0;
// }

