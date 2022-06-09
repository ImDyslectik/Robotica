#include "grove.h"

int main(){
    init();
    sleep(1);
    int x;
    for (int i = 0; i <= 60; i++){
        pinMode(i, 0);
        sleep(1);  
        x = analogRead(i); 
        printf("found value %d on pin %d!\n", x, i);
    }
    
    return 0;
}