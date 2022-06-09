//
// Created by Jordy on 13/05/2022.
//

#ifndef AX12_H
#define AX12_H

#define HEADER_ONE_BYTE        0xFF
#define HEADER_TWO_BYTE        0xFF
#define WRITE_BYTE             0x03
#define COMMAND_SPEED_BYTE     0x20
#define COMMAND_MOVE_BYTE      0x1E
#define COMMAND_CW_LIMIT_BYTE  0x06
#define COMMAND_CCW_LIMIT_BYTE 0x08

#define GET_BYTE(a, b) ((b) > (0) ? (a>>8) : (a&0xFF))

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AX12{
    int ID;
    bool wheelMode;
} ax12;

void sendPacket(u_int8_t*);
u_int8_t getChecksum(u_int8_t*);

void ax12Move(ax12, int);
void ax12Speed(ax12, int);
void ax12AngleCWLimit(ax12, int);
void ax12AngleCCWLimit(ax12, int);


#endif //AX12_H