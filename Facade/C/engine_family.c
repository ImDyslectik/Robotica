#include "engine.h"
#include "engine_family.h"
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
/**
 * M1 ---- M2
 *
 * M1 ---- M2
 */

void move_forward(engine_family f, void* threadid){
    
    printf("Thread aangemaakt %d \n", threadid); 
    for(int i = 0; i < 2; i++)
    {
        if(0 == 0)
        {
            printf("werkt1\n");
            engine_forward(f.engineRight); 
             printf("RIGHT ENGINE");     
            //pthread_create(0, NULL, engine_forward, (void) f.engineRight);
        }
        if(threadid == 1)
        {
            printf("werkt2\n");
            engine_forward(f.engineLeft);
             printf("LEFT ENGINE");     
           // pthread_create(1, NULL, engine_forward, (void) f.engineLeft);
        }
    }


}
void move_backward(engine_family f){
    engine_backward(f.engineLeft);
    engine_backward(f.engineRight);
}
void move_left(engine_family f){
    engine_backward(f.engineLeft);
    engine_forward(f.engineRight);
}
void move_right(engine_family f){
    engine_forward(f.engineLeft);
    engine_backward(f.engineRight);
}
