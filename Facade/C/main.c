#include "ttyHandler.h"
#include "ax12.h"
#include <stdio.h>
#include "engine_family.h"
#include "../../Pipes/C/readFirst.h"
#include <wiringPi.h>
#include <pthread.h>

void PrintHello(void *threadid) {
   printf("Hello World! Thread ID, %d\n", threadid);
   pthread_exit(NULL);
}

int main1(int argc, char *argv[] ){

    // int threads[4];
    // threads[0] = 0;
    // threads[1] = 1;
    // //for( int i = 0; i < 2; i++ ) 
    // //{
    // //    pthread_create(&threads[i], NULL, PrintHello, (void* )i);
    // //}
    // //    pthread_exit(NULL);
    // //threads[2] = 2;
    // //threads[3] = 3;
    // //set up wiringpi stuff, and set the gpio pin to output
    wiringPiSetup();

    pinMode(1, OUTPUT);
    // int engine_command[2];
    // readSetup(engine_command);

    // while(1){
    // reading(engine_command);
    // //init a servo with the first argument given in the console
    // //ax12 servo = {atoi(argv[1])};
    // printf("%d \n",engine_command[0]);
    // printf("%d \n",engine_command[1]);

    

    // engine motor1 = {23,26,true};
    // engine motor2 = {24,25,false};
    // engine_family x = {motor1, motor2}; 
    
    // for( int i = 0; i < 2; i++ ) 
    // {
    //     int threadid = i;
    // //printf("thread id %d\n", threadid);
    // // pthread_create(&threads[i], NULL, move_forward,(((void*) &threadid),((engine_family*) &x)));
    // //pthread_create(&threads[i], NULL, PrintHello,(void*) threadid);
    // }
    // pthread_exit(NULL);

}

int main5(){
    wiringPiSetup();
    pinMode(1, OUTPUT);
    ax12 servo = {18, true};
    int potentio = 500;

    while (potentio != 500) {
        if (potentio < 500){
            ax12Speed(servo, 100);
        }
        else{
            ax12Speed(servo, -100);
        }
    }
}


int main2(){
    wiringPiSetup();
    pinMode(1, OUTPUT);

    ax12 s1 = {2, false};
    ax12 s2 = {4, false};
    ax12Speed(s1, 30);
    ax12Speed(s2, 30);
    int offset = 90;
    ax12Move(s1, (150+0));
    ax12Move(s2, (150-0));

}

int main(){
	wiringPiSetup();
	pinMode(1,OUTPUT);
	engine motor1 = {23,26,true};
	engine motor2 = {24,25,false};
	engine_family x = {motor1,motor2};
	
	move_backward(x);
}

int main7(int argc, char *argv[] ){
    // //set up wiringpi stuff, and set the gpio pin to output
    wiringPiSetup();

    pinMode(1, OUTPUT);
    int engine_command[2];
    readSetup(engine_command);

    while(1){
        reading(engine_command);
        printf("%d \n",engine_command[0]);
        printf("%d \n",engine_command[1]);

        engine motor1 = {23,26,true};
        engine motor2 = {24,25,false};
        engine_family x = {motor1, motor2}; 
    
        if (engine_command[0] == 1 && engine_command[1] == 1){
            printf("forward \n");
    	    move_forward(x,1);
        }
        if (engine_command[0] == 0 && engine_command[1] == 0){
            printf("back \n");
    	    move_backward(x);
        }
        if (engine_command[0] == 0 && engine_command[1] == 1){
            printf("left \n");
    	    move_left(x);
        }
        if (engine_command[0] == 1 && engine_command[1] == 0){
            printf("right \n");
        	move_right(x);
        };
    }
    return 0;
}


int main3(){
    wiringPiSetup();
    pinMode(1, OUTPUT);

    ax12 s = {2, false};
    ax12Move(s, 100);
    sleep(3);
    ax12Move(s, 200);
}
