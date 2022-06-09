#include "ax12.h"
#include <stdio.h>
#include <wiringPi.h>
#include "ttyHandler.h"

 int main2(){
     wiringPiSetup();
     pinMode(18, OUTPUT);

     ax12 s = {18, true};
     ax12Speed(s, 100);
     sleep(3);
     ax12Speed(s, 0);
     sleep(3);
     ax12Speed(s, -100);
     sleep(3);
     ax12Speed(s, 0);
 }
