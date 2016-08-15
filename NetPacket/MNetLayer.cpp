#include "NetLayer.h"

int MNetLayer(u_char *payload, int payloadLength, ip_header ip_header, u_char **frame)
{
	*(frame) = (u_char*)malloc(payloadLength+20);
	u_char *uncheckframe = (u_char*)malloc(20);
	memcpy(uncheckframe, ip_header.ver_len,1);//
	memcpy((uncheckframe+1),ip_header.tos, 1);
	memcpy((uncheckframe+2),ip_header.tlen, 2);
	memcpy(uncheckframe+4,ip_header.identification, 2);
	memcpy(uncheckframe+6,ip_header.flags_offset, 2);
	memcpy(uncheckframe+8,ip_header.ttl,1);
	memcpy(uncheckframe+9,ip_header.proto,1);
	*(ip_header.crc) = 0x0000;
	memcpy(uncheckframe+10,ip_header.crc, 2);
	memcpy(uncheckframe+12,ip_header.saddr,4);
	memcpy(uncheckframe+16,ip_header.daddr,4);
	*(ip_header.crc) = ip_header_checksum((USHORT *)uncheckframe, 20);
	memcpy(uncheckframe + 10, ip_header.crc, 2);
	memcpy(*frame, uncheckframe, 20);
	memcpy((*frame+20),payload,payloadLength);
	return payloadLength + 20;
}

unsigned short ip_header_checksum(USHORT* buffer, int size)
{
	unsigned long cksum = 0;
	while (size>1)
	{
		cksum += *buffer++;
		size -= sizeof(USHORT);
	}
	if (size)
	{
		cksum += *(UCHAR*)buffer;
	}
	cksum = (cksum>>16) + (cksum & 0xffff);
	cksum += (cksum>>16);
	return (USHORT)(~cksum);
}

unsigned short ver_len_input(int ver, int len)
{
	/*暂时没有完成实际的计算，待完成*/
	return (u_int8_t)0x45;//vision 4 len 20
}

void IPheaderInit(ip_header * ipheader)
{
	ipheader->crc = (u_short*)malloc(sizeof(u_short));
	ipheader->flags_offset= (u_short*)malloc(sizeof(u_short));
	ipheader->identification= (u_short*)malloc(sizeof(u_short));
	ipheader->proto= (u_char*)malloc(sizeof(u_char));
	ipheader->tlen= (u_short*)malloc(sizeof(u_short));
	ipheader->tos= (u_char*)malloc(sizeof(u_char));
	ipheader->ttl= (u_char*)malloc(sizeof(u_char));
	ipheader->ver_len = (u_int8_t*)malloc(sizeof(u_int8_t));
	ipheader->daddr = (ip_address*)malloc(sizeof(ip_address));
	ipheader->saddr = (ip_address*)malloc(sizeof(ip_address));
}