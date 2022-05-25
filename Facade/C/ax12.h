//
// Created by Jordy on 13/05/2022.
//

#ifndef UNTITLED_AX12_H
#define UNTITLED_AX12_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AX12{
    int ID;
    bool wheelMode;
} ax12;

void ax12Move(ax12, int);
void ax12Speed(ax12, int);

void sendPacket(u_int8_t*);

#endif //UNTITLED_AX12_H
