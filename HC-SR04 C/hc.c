#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TRIG 4
#define ECHO 5

static int sent()
{
    long current_micros = micros();
	long start = 0;
	long end = 0;
	float distance = 0;
    long  failure = current_micros + 500000;
	
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
	
	printf("Distance: %.2f cm.\n", distance);
	return 1;
}

int main (int argc, char *argv[])
{	
	wiringPiSetup ();
        pinMode(TRIG, OUTPUT);
        pinMode(ECHO, INPUT);
	while(1==1){
	sent();
	delay(50);
        }
	return 0;
}

	
