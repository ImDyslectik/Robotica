#include <wiringPi.h>
#include "../../Pipes/C/readFirst.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <pthread.h>

#define TRIG 4
#define ECHO 5

static int sent(double steady_distance)
{
    long current_micros = micros();
	long start = 0;
	long end = 0;
	double distance = 0;
	double range_distance = 2;
    long failure = current_micros + 500000;
	int max = 0;
	int min = 0;
	int steady = 0;
	
	digitalWrite(TRIG, LOW);
	delayMicroseconds(2);
	
	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10); 
	digitalWrite(TRIG, LOW);
	
	while (digitalRead(ECHO) == LOW && micros() < failure) {
	}
	
	start = micros();
	
	while (digitalRead(ECHO) == HIGH && micros() < failure) {
	}
	
	end = micros();
	
	distance = (float) (end - start) * 0.017150;
	max = floor(distance + range_distance);
	min = floor(distance - range_distance);
	steady = floor(steady_distance);

	if(steady > max)
	{
	steady_distance = distance;
	//printf("Distance: %.2f cm.\n", steady_distance);
	}
	else if(steady < min)
	{
	steady_distance = distance;
	//printf("Distance: %.2f cm.\n", steady_distance);
	}
	else
	{
	//printf("Distance: %.2f cm.\n", steady_distance);
	}

	return steady_distance;
}

int* sensor (int* engine_command[])
{	
	wiringPiSetup();
	int Stop = 1;
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
	double steady_distance = 0;
	while(1){
		steady_distance = sent(steady_distance);
		if (steady_distance < 10){
			engine_command[0] == 900;
			engine_command[1] == 900;
			printf("Distance is kinda low\n",Stop);
		}
	}
	//delay(50);
	return 0;
}

	

