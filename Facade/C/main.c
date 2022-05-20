#include "ttyHandler.h"
#include "ax12.h"
#include <stdio.h>

#include <wiringPi.h>

int main(int argc, char *argv[] ){
    wiringPiSetup();
    pinMode(1, OUTPUT);

    ax12 servo = {atoi(argv[1])};

    ax12Move(servo, atoi(argv[2]));
    return 0;
}