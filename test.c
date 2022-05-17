#include <wiringPi.h>
#include <softPwm.h>

int main(void)
{
    const int pinA = 23;
    const int pinB = 26;
    const int delay = 5000;

    softPwmCreate(pinA,0,5);
    softPwmCreate(pinB,0,5);

    wiringPiSetup();

    pinMode(led, OUTPUT);

    while (1) {
        softPwmWrite(pinA,0);
        softPwmWrite(pinB,0);
        delay(delay);
        softPwmWrite(pinA,2);
        softPwmWrite(pinB,0);
        delay(delay);
        softPwmWrite(pinA,5);
        softPwmWrite(pinB,0);
        delay(delay);
        softPwmWrite(pinA,2);
        softPwmWrite(pinB,0);
        delay(delay);
    }
    return 0;
}