#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<termio.h>
#include<linux/serial.h>
#include<time.h>

#include<wiringPi.h>


/*
code found to alter baudrate found at https://stackoverflow.com/questions/23492088/c-code-for-non-standard-baud-rate-on-debian-raspberry-pi
**/
static int rate_to_constant(int baudrate) {
#define B(x) case x: return B##x
        switch(baudrate) {
        B(50);     B(75);     B(110);    B(134);    B(150);
        B(200);    B(300);    B(600);    B(1200);   B(1800);
        B(2400);   B(4800);   B(9600);   B(19200);  B(38400);
        B(57600);  B(115200); B(230400); B(460800); B(500000);
        B(576000); B(921600); B(1000000);B(1152000);B(1500000);
    default: return 0;
    }
#undef B
}

int main() {

    wiringPiSetup();

    pinMode(1, OUTPUT);

    struct termios options;
    struct serial_struct serinfo;
    int fd;
    int speed = 0;
    int rate = 1000000;

    /* Open and configure serial port */
    if ((fd = open("/dev/ttyAMA0",O_RDWR|O_NOCTTY)) == -1)
    {
        return -1;
    }

    // if you've entered a standard baud the function below will return it
    speed = rate_to_constant(rate);

    printf("%d\n", speed);

    if (speed == 0) {
        /* Custom divisor */
        serinfo.reserved_char[0] = 0;
        if (ioctl(fd, TIOCGSERIAL, &serinfo) < 0)
            return -1;
        serinfo.flags &= ~ASYNC_SPD_MASK;
        serinfo.flags |= ASYNC_SPD_CUST;
        serinfo.custom_divisor = (serinfo.baud_base + (rate / 2)) / rate;
        if (serinfo.custom_divisor < 1)
            serinfo.custom_divisor = 1;
        if (ioctl(fd, TIOCSSERIAL, &serinfo) < 0)
            return -1;
        if (ioctl(fd, TIOCGSERIAL, &serinfo) < 0)
            return -1;
        if (serinfo.custom_divisor * rate != serinfo.baud_base) {
            warnx("actual baudrate is %d / %d = %f",
                  serinfo.baud_base, serinfo.custom_divisor,
                  (float)serinfo.baud_base / serinfo.custom_divisor);
        }
    }

    printf("%d\n", speed);

    fcntl(fd, F_SETFL, 0);
    tcgetattr(fd, &options);
    cfsetispeed(&options, speed ?: B38400);
    cfsetospeed(&options, speed ?: B38400);
    cfmakeraw(&options);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~CRTSCTS;
    if (tcsetattr(fd, TCSANOW, &options) != 0)
    {
        //return -1;
    }


    //return fd;

    u_int8_t buff1[9];
    u_int8_t buff2[6];

    buff1[0]  = 0xFF;
    buff1[1]  = 0xFF;
    buff1[2]  = 0x04;
    buff1[3]  = 0x05;
    buff1[4]  = 0x03;
    buff1[5]  = 0x1E;
    buff1[6]  = 0x50;
    buff1[7]  = 0x02;
    buff1[8]  = 0x83;
    printf("%02X\n", buff1);
    while(1){
    	digitalWrite(1, HIGH); 
        printf("writing!\n"); 
        write(fd,buff1, sizeof(buff1)); 
        printf("done writing!\n"); 
        usleep(200); 
        digitalWrite(1, LOW); 
        printf("reading!\n"); 
        read(fd, buff2, sizeof(buff2));
        for (int i = 0; i < sizeof(buff2); i++){
            printf("%02X cool\n", buff2[i]);
        }
         
        delay(1000);
    }

    write(fd,&buff1,sizeof(buff1));
    read(fd,&buff2,sizeof(buff2));

    //int i;
    //for (i = 0; i < sizeof(ping_rec); i++)
    //{
    //    printf("%d ",ping_rec[i]);
    //}


    close(fd);
    return 0;
}