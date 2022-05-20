
//
// Created by Jordy on 13/05/2022.
//
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

#include "ax12.h"

#include <wiringPi.h>

void ax12Move(ax12 s, int degrees){
    u_int8_t packet[9];
    u_int8_t response[6];

    uint16_t d = (uint16_t)(degrees * (1023.0 / 300.0));


    packet[0] = 0xff;
    packet[1] = 0xff;
    packet[2] = s.ID&0xff;
    packet[3] = 0x05;
    packet[4] = 0x03;
    packet[5] = 0x1E;
    packet[6] = d&0xff;
    packet[7] = d>>8;
    packet[8] = ~((packet[2]+packet[3]+packet[4]+packet[5]+packet[6]+packet[7]))&0xFF;

    int fd = getFileDescriptor();

    digitalWrite(1, HIGH); 
    write(fd,packet, sizeof(packet)); 
    usleep(150); 
    digitalWrite(1, LOW); 
    read(fd, response, sizeof(response));

    for (int i = 0; i < sizeof(response); i++){
        printf("%02X\n", response[i]);
    }

    close(fd);
    return ;
}

