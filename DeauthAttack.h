// DeauthAttack.h

#ifndef _DEAUTH_ATTACK_H_
#define _DEAUTH_ATTACK_H_

#include "mac.h"

typedef struct Mac Mac;

struct deauth_packet
{
    uint8_t data[37];
} __attribute__((__packed__));

typedef deauth_packet DeauthPacket;

void InitDeauthPacket(DeauthPacket* packet);
void InitDeauthApBroadcast(DeauthPacket* packet, Mac& apMac);
void InitDeauthApUnicast(DeauthPacket* packet, Mac& apMac, Mac& staMac);
void InitDeauthStaUnicast(DeauthPacket* packet, Mac& apMac, Mac& staMac);

#endif