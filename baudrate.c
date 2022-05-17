#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <asm/termios.h>

#include <wiringPi.h>

int main(){
    struct termios2 tty;
    int fd = open("/dev/ttyAMA0", O_RDWR);
    ioctl(fd, TCGETS2, &tty);
    tty.c_cflag &= ~CBAUD;
    tty.c_cflag |= BOTHER;
    tty.c_ispeed = 1000000;
    tty.c_ospeed = 1000000;
    ioctl(fd, TCSETS2, &tty);
    ioctl(fd, TCGETS2, &tty);
    printf("%d\n", tty.c_ispeed);
    close(fd);
}