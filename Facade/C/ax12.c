
//
// Created by Jordy on 13/05/2022.
//
#include <stdio.h>
#include <stdint.h>
#include "ax12.h"

void ax12Move(ax12 s, int degrees){
    unsigned short int packet[9];

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

    for(int i = 0; i < 9; i++){
        printf("%02X\n",packet[i]);
    }

}
