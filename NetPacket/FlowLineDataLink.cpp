#include "DataLink.h"
#include "PublicLib.h"
#include <stdlib.h>
int MEthernet(u_char *payload, int payloadLength, Etllernet *Ethernet, u_char **frame)
{
	*(frame) = (u_char*)malloc(payloadLength+18);
	u_char *uncheckframe = (u_char*)malloc(payloadLength + 14);
	memcpy(uncheckframe, Ethernet->decmac,6);
	memcpy(uncheckframe+6, Ethernet->srcmac,6);
	memcpy(uncheckframe+12,Ethernet->type,sizeof(u_int16_t));
	memcpy(uncheckframe+14, Ethernet->PayLoad,payloadLength);
	u_char * fsc = (u_char*)malloc(4);
	uint32_t fscc = crc32(uncheckframe,payloadLength + 14);
	memcpy(*(frame), uncheckframe, payloadLength + 14);
	memcpy(*(frame)+payloadLength+14, &fscc,sizeof(uint32_t));
	return payloadLength+18;
}

void EthernetInit(Etllernet* e)
{
	e->decmac = (u_char*)malloc(6);
	e->srcmac = (u_char*)malloc(6);
	e->type = (u_int16_t*)malloc(2);
}

u_char* SetMacAddr(u_char addr1, u_char addr2, u_char addr3, u_char addr4, u_char addr5, u_char addr6)
{
	u_char *MAC = (u_char *)malloc(6);

	memcpy(MAC, &addr1, 1);
	memcpy(MAC+1, &addr2, 1);
	memcpy(MAC+2, &addr3, 1);
	memcpy(MAC+3, &addr4, 1);
	memcpy(MAC+4, &addr5, 1);
	memcpy(MAC+5, &addr6, 1);

	return MAC;
}