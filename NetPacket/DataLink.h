#pragma once
#include "PublicLib.h"
#include "pcap.h"


typedef struct Etllernet {
	u_char *decmac;
	u_char *srcmac;
	u_int16_t *type;
	u_char *PayLoad;
}Etllernet;


int MEthernet(u_char *payload,int payloadLength , Etllernet *Ethernet,u_char **frame);
void EthernetInit(Etllernet* e);
u_char* SetMacAddr(u_char addr1, u_char addr2, u_char addr3, u_char addr4, u_char addr5, u_char addr6);
