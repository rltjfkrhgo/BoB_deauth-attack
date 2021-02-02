// DeauthAttackMain.cpp

#include <cstdio>
#include <pcap.h>
#include "DeauthAttack.h"

void usage() {
    printf("syntax: deauth-attack <interface> <ap mac> [<station mac>]\n");
    printf("sample: deauth-attack 00:11:22:33:44:55 66:77:88:99:AA:BB\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3 || argc != 4) {
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

/*
    int res = pcap_sendpacket(
        handle, 
        reinterpret_cast<const u_char*>( &(session[i].arpInfectPacket) ), 
        sizeof(EthArpPacket));
    if (res != 0) {
        fprintf(stderr, "pcap_sendpacket return %d error=%s\n", res, pcap_geterr(handle));
    }
    */

    pcap_close(handle);

    return 0;
}