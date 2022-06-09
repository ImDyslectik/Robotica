#include "ax12.h"
#include <stdio.h>
#include <wiringPi.h>
#include "ttyHandler.h"

 int main6(){
     wiringPiSetup();
     pinMode(18, OUTPUT);

     ax12 s1 = {2, false};
     ax12 s2 = {4, false};
     ax12Speed(s1, 20);
     ax12Speed(s2, 20);
     ax12Move(s1, 150+105);
     ax12Move(s2, 150-105);
     sleep(2);
     ax12Move(s1, 150+20);
     ax12Move(s2, 150-20);
/*
     ax12 s3 = {18, true};
     ax12Speed(s3, 100);
     sleep(7);
     ax12Speed(s3, -100);
     sleep(7);
     ax12Speed(s3, 0);
     */
 }