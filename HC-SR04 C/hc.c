#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TRIG 4
#define ECHO 5

static int sent()
{
	long start = 0;
	long end = 0;
	float distance = 0;
	
	digitalWrite(TRIG, LOW);
	delayMicroseconds(2);
	
	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10); 
	digitalWrite(TRIG, LOW);
	
	while (digitalRead(ECHO) == LOW) {
	}
	
	start = micros();
	
	while (digitalRead(ECHO) == HIGH) {
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

	
