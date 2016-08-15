#include "Init.h"
#include "PacketSend.h"
#include "PublicLib.h"
#include "DataLink.h"
#include "NetLayer.h"
/********测试功能专用******/
void test()
{
	pcap_t *adhandle = NULL;
	GetDevHandle(&adhandle);
	Etllernet e;
	ip_header ipheader;// =(ip_header *) malloc(sizeof(ip_header));
	u_char *frame = NULL;
	u_char *packet = NULL;
	EthernetInit(&e);
	
	IPheaderInit(&ipheader);
	*(ipheader.ver_len) = 0x45;
	*(ipheader.tos) = 0x05;
	*(ipheader.tlen) = 0x30;
	*(ipheader.identification) = 0x3456;
	*(ipheader.flags_offset) = 0x0114;
	*(ipheader.ttl) = 0x11;
	*(ipheader.proto) = 0x33;
	*(ipheader.crc) = 0x00;


	ipheader.saddr->byte1 = 0xAC;
	ipheader.saddr->byte2 = 0x1F;
	ipheader.saddr->byte3 = 0xC8;
	ipheader.saddr->byte4 = 0x02;

	ipheader.daddr->byte1 = 0xFF;
	ipheader.daddr->byte2 = 0xFF;
	ipheader.daddr->byte3 = 0xFF;
	ipheader.daddr->byte4 = 0xFF;


	u_char * tempload = (u_char *)malloc(20);
	packet = (u_char *)malloc(40);
	int lenip = MNetLayer(tempload,20,ipheader,&packet);



	e.decmac = SetMacAddr(0x11,0x22,0x33,0x44,0x55,0x66);
	e.srcmac = SetMacAddr(0x11, 0x22, 0x33, 0x44, 0x55, 0x66);
	*(e.type) =0x0008;
	e.PayLoad = packet;


	int length = MEthernet((e.PayLoad), lenip,&e,&frame);

	SendPacketTo(&adhandle, frame, length);
	
}
