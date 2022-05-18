#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <asm/termios.h>

#include <wiringPi.h>

int main(){
    setupWiringPi();
    pinMode(1, OUTPUT);
    struct termios2 tty;
    int fd = open("/dev/ttyAMA0", O_RDWR);
    ioctl(fd, TCGETS2, &tty);
    tty.c_cflag &= ~CBAUD;
    tty.c_cflag |= BOTHER;
    tty.c_ispeed = 1000000;
    tty.c_ospeed = 1000000;
    ioctl(fd, TCSETS2, &tty);
    char * buff1[9];
    char * buff2[100];
    buff1[0] = "0xFF";
    buff1[1] = "0xFF";
    buff1[2] = "0x15";
    buff1[3] = "0x05";
    buff1[4] = "0x03";
    buff1[5] = "0x1E";
    buff1[6] = "0x05";
    buff1[7] = "0x02";
    buff1[8] = "0xBD";
    digitalWrite(1, HIGH);
    write(fd, buff1, sizeof(buff1));
    sleep(0.0000001);
    digitalWrite(1, LOW);
    read(fd, buff2, sizeof(buff2));
    printf("%02X\n", buff2);
    return 0;
}