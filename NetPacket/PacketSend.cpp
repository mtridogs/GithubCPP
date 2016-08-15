#include "PublicLib.h"
#include "Init.h"


/*****************************************/
/*****************************************/
int SendPacketTo(pcap_t **adhandle, u_char *PacketData, int PacketDataLength)
{
	if (pcap_sendpacket(*adhandle, PacketData, PacketDataLength) != 0)
	{
		printf("[!]Error: Send Packet Error!\n");
		return Fun_NotNormal;
	}
	return Fun_Normal;
}
/*****************************************/
/*****************************************/
