
//
// Created by Jordy on 13/05/2022.
//
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "ax12.h"

#include <wiringPi.h>

void sendPacket(u_int8_t packet[]){
    int reading = 0;
    
    int fd = getFileDescriptor();

    int size = packet[3] + 4; 
    

    digitalWrite(1, HIGH); 
    write(fd,packet, size); 
    usleep(200); 
    digitalWrite(1, LOW); 
    if (reading){
        u_int8_t response[6];
        read(fd, response, sizeof(response));
        for (int i = 0; i < sizeof(response); i++){
            printf("%02X\n", response[i]);
        }
    }
    
    close(fd);
    return;
}

void ax12Move(ax12 s, int degrees){
    u_int8_t packet[9];

    uint16_t d = (uint16_t)(degrees * (1023.0 / 300.0));


    packet[0] = HEADER_ONE_BYTE;
    packet[1] = HEADER_TWO_BYTE;
    packet[2] = s.ID&0xff;
    packet[3] = 0x05;
    packet[4] = WRITE_BYTE;
    packet[5] = COMMAND_MOVE_BYTE;
    packet[6] = d&0xff;
    packet[7] = d>>8;
    packet[8] = ~((packet[2]+packet[3]+packet[4]+packet[5]+packet[6]+packet[7]))&0xFF;

    sendPacket(packet);
    return;
}

void ax12Speed(ax12 s, int speed){
    u_int8_t packet[9];

    uint16_t d;

    if (s.wheelMode){
        if (speed < 0){
            d = (uint16_t)(-speed * (1023.0 / 100.0));
        } else {
            d = (uint16_t)(speed * (1023.0 / 100.0)) + 1024;
        }
    } else {
        d = (uint16_t)(speed * (1023.0 / 100.0));
    }

    packet[0] = HEADER_ONE_BYTE;
    packet[1] = HEADER_TWO_BYTE;
    packet[2] = s.ID&0xff;
    packet[3] = 0x05;
    packet[4] = WRITE_BYTE;
    packet[5] = COMMAND_SPEED_BYTE;
    packet[6] = d&0xff;
    packet[7] = d>>8;
    packet[8] = ~((packet[2]+packet[3]+packet[4]+packet[5]+packet[6]+packet[7]))&0xFF;

    sendPacket(packet);
    
    return;
}

