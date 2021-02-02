// DeauthAttack.h

#ifndef _DEAUTH_ATTACK_H_
#define _DEAUTH_ATTACK_H_

#include "mac.h"

typedef struct Mac Mac;

struct deauth_packet
{
    static const uint8_t  TYPE = 0xc0;
    uint8_t  radiotab[11];
    uint8_t  type;
    uint8_t  flags;
    uint8_t  duration[2];
    uint8_t  receiver[6];
    uint8_t  transmitter[6];
    uint8_t  bssid[6];
    uint8_t  sequence[2];
    uint8_t  management[2];
} __attribute__((__packed__));

typedef deauth_packet DeauthPacket;

void InitDeauthPacket(DeauthPacket* packet);
void InitDeauthApBroadcast(DeauthPacket* packet, Mac& apMac);
void InitDeauthApUnicast(DeauthPacket* packet, Mac& apMac, Mac& staMac);
void InitDeauthStaUnicast(DeauthPacket* packet, Mac& apMac, Mac& staMac);

#endif