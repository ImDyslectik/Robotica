
//
// Created by Jordy on 13/05/2022.
//
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "ax12.h"

#include <wiringPi.h>

/*
Function used to send packets to the specified servo
@param packet[] int array containing the command
*/
void sendPacket(u_int8_t packet[]){    
    //get a fileDescriptor which has a baudrate of 1M
    int fd = getFileDescriptor();

    //calculate the size of the packet based on the packet itself
    int size = packet[3] + 4; 
    
    //set gpio pin 1 high so we tell the servo we're writing
    digitalWrite(1, HIGH); 
    write(fd,packet, size); 
    //wait to make sure the command went through
    usleep(20); 
    //set gpio pin 1 low so we can listen to the servo
    digitalWrite(1, LOW); 

    //if we're debugging we're writing the response to a packet and printing it to the screen
    #ifdef DEBUG
    u_int8_t response[6];
    read(fd, response, sizeof(response));
    for (int i = 0; i < sizeof(response); i++){
        printf("%02X\n", response[i]);
    }
    #endif
    close(fd);
    return;
}

/*
Function used to calculate the checksum of a packet, it sums most of the packets then inverts the sum.
@param packet array used to calculate the checksum
@returns u_int8_t the checksum
*/
u_int8_t getChecksum(u_int8_t packet[]){
    //calculate the size of the packet based on the packet itself
    int size = packet[3] + 4;
    int sum = 0;

    for (int i = 2; i < size-1; i++){
        sum += packet[i];
    }

    return ~(sum)&0xFF;
}

/*
Function used to make the servo move to a certain amount of degrees
@param s ax12 struct which tells us which servo to move
@param degrees set rotation we want the servo to move to
*/
void ax12Move(ax12 servo, int degrees){
    //define a buffer for a packet
    u_int8_t packet[9];

    //taking the amount of degrees calculating what hex it should be
    uint16_t degreesHex = (uint16_t)(degrees * (1023.0 / 300.0));
    
    //filling in the packet
    packet[0] = HEADER_ONE_BYTE;
    packet[1] = HEADER_TWO_BYTE;
    packet[2] = servo.ID&0xFF;
    packet[3] = 0x05; //amount of bytes left in the packet
    packet[4] = WRITE_BYTE;
    packet[5] = COMMAND_MOVE_BYTE;
    packet[6] = GET_BYTE(degreesHex, 0);
    packet[7] = GET_BYTE(degreesHex, 1);
    packet[8] = getChecksum(packet); //calculate checksum 

    sendPacket(packet);
    return;
}

/*
Function used to make the servo move at a certain speed, if wheel mode it'll spin until you tell it to stop
@param s ax12 struct which tells us which servo to move
@param speed set percentage of speed you want the servo to move at
*/
void ax12Speed(ax12 servo, int speed){
    //define a buffer for a packet
    u_int8_t packet[9];

    //taking the speed in percentage calculating what hex it should be
    uint16_t speedHex;

    //if we're in wheel mode the speed get's calculated differently
    if (servo.wheelMode){
        if (speed < 0){
            speedHex = (uint16_t)(-speed * (1023.0 / 100.0));
        } else {
            speedHex = (uint16_t)(speed * (1023.0 / 100.0)) + 1024;
        }
    } else {
        speedHex = (uint16_t)(speed * (1023.0 / 100.0));
    }

    //filling in the packet
    packet[0] = HEADER_ONE_BYTE;
    packet[1] = HEADER_TWO_BYTE;
    packet[2] = servo.ID&0xFF;
    packet[3] = 0x05; //amount of bytes left in the packet
    packet[4] = WRITE_BYTE;
    packet[5] = COMMAND_SPEED_BYTE;
    packet[6] = GET_BYTE(speedHex, 0);
    packet[7] = GET_BYTE(speedHex, 1);
    packet[8] = getChecksum(packet);

    sendPacket(packet);
    
    return;
}

/*
Function used to set a limit to how far the servo can turn clockwise
@param servo Servo which you want to use
@param limit limit to which the servo can turn
*/
ax12AngleCWLimit(ax12 servo, int limit){
    u_int8_t packet[9];

    uint16_t limitHex = (uint16_t)(limit * (1023.0 / 300.0));

    //filling in the packet
    packet[0] = HEADER_ONE_BYTE;
    packet[1] = HEADER_TWO_BYTE;
    packet[2] = servo.ID&0xFF;
    packet[3] = 0x05; //amount of bytes left in the packet
    packet[4] = WRITE_BYTE;
    packet[5] = COMMAND_CW_LIMIT_BYTE;
    packet[6] = GET_BYTE(limitHex, 0);
    packet[7] = GET_BYTE(limitHex, 1);
    packet[8] = getChecksum(packet); //calculate checksum 

    sendPacket(packet);
    return;
}

/*
Function used to set a limit to how far the servo can turn counter-clockwise
@param servo Servo which you want to use
@param limit limit to which the servo can turn
*/
ax12AngleCCWLimit(ax12 servo, int limit){
    u_int8_t packet[9];

    uint16_t limitHex = (uint16_t)(limit * (1023.0 / 300.0));
    
    //filling in the packet
    packet[0] = HEADER_ONE_BYTE;
    packet[1] = HEADER_TWO_BYTE;
    packet[2] = servo.ID&0xFF;
    packet[3] = 0x05; //amount of bytes left in the packet
    packet[4] = WRITE_BYTE;
    packet[5] = COMMAND_CCW_LIMIT_BYTE;
    packet[6] = GET_BYTE(limitHex, 0);
    packet[7] = GET_BYTE(limitHex, 1);
    packet[8] = getChecksum(packet); //calculate checksum 

    sendPacket(packet);
    return;
}