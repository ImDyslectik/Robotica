#include "grovepi.h"
using namespace GrovePi;

int main(){
    int pin = 0;
    int incoming;
    try{
        initDevice(0x08);
        pinMode(pin, INPUT);

        while(true){
            incoming = analogRead(pin);
            printf("[pin %d][analog read = %d]\n", pin, incoming);
        
            delay(10);
        }
    }
    	catch (I2CError &error)
	{
		printf(error.detail());

		return -1;
	}

    return 0;
}