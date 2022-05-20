#include <wiringPi.h>
#include <softPwm.h>

int main(void)
{    
    wiringPiSetup();
    const int pinA = 23;
    const int pinB = 26;
    //const int pinC = 24;
    //const int pinD = 25;
    //const int delay = 10000;

    softPwmCreate(pinA,0,5);
    softPwmCreate(pinB,0,5);
    //softPwmCreate(pinC,0,5);
    //softPwmCreate(pinD,0,5);


    while (1) {
        softPwmWrite(pinA,0);
        softPwmWrite(pinB,0);
        //softPwmWrite(pinA,0);
        //softPwmWrite(pinD,0);
        delay(1000);
        softPwmWrite(pinA,2);
        softPwmWrite(pinB,0);
        //softPwmWrite(pinC,0);
        //softPwmWrite(pinD,2);
        delay(2000);
        softPwmWrite(pinA,5);
        softPwmWrite(pinB,0);
        //softPwmWrite(pinC,0);
        //softPwmWrite(pinD,5);
        delay(2000);
        softPwmWrite(pinA,2);
        softPwmWrite(pinB,0);
        //softPwmWrite(pinC,0);
        //softPwmWrite(pinD,2);
        delay(10000);
    }
    softPwmWrite(pinA,0);
    softPwmWrite(pinB,0);
    //softPwmWrite(pinA,0);
    //softPwmWrite(pinD,0);

    return 0;
}