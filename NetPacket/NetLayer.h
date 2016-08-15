#pragma once
#include "PublicLib.h"


typedef struct ip_address {
	u_char byte1;
	u_char byte2;
	u_char byte3;
	u_char byte4;
}ip_address;
typedef struct ip_header {
	u_int8_t *ver_len;        // �汾 (4 bits) + �ײ����� (4 bits)
	u_char  *tos;            // ��������
	u_short *tlen;           // �ܳ�
	u_short *identification; // ��ʶ
	u_short *flags_offset;       // ��־λ (3 bits) + ��ƫ����(Fragment offset) (13 bits)
	u_char  *ttl;            // ���ʱ��
	u_char  *proto;          // Э��  tcp6  udp 17
	u_short *crc;            // �ײ�У���
	ip_address  *saddr;      // Դ��ַ
	ip_address  *daddr;      // Ŀ�ĵ�ַ
	//u_int   *op_pad;         // ѡ�������
}ip_header;

int MNetLayer(u_char *payload, int payloadLength, ip_header ip_header, u_char **frame);
unsigned short ip_header_checksum(USHORT* buffer, int size);
unsigned short ver_len_input(int ver,int len);
void IPheaderInit(ip_header * ipheader);