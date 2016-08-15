#pragma once
#include "PublicLib.h"


typedef struct ip_address {
	u_char byte1;
	u_char byte2;
	u_char byte3;
	u_char byte4;
}ip_address;
typedef struct ip_header {
	u_int8_t *ver_len;        // 版本 (4 bits) + 首部长度 (4 bits)
	u_char  *tos;            // 服务类型
	u_short *tlen;           // 总长
	u_short *identification; // 标识
	u_short *flags_offset;       // 标志位 (3 bits) + 段偏移量(Fragment offset) (13 bits)
	u_char  *ttl;            // 存活时间
	u_char  *proto;          // 协议  tcp6  udp 17
	u_short *crc;            // 首部校验和
	ip_address  *saddr;      // 源地址
	ip_address  *daddr;      // 目的地址
	//u_int   *op_pad;         // 选项与填充
}ip_header;

int MNetLayer(u_char *payload, int payloadLength, ip_header ip_header, u_char **frame);
unsigned short ip_header_checksum(USHORT* buffer, int size);
unsigned short ver_len_input(int ver,int len);
void IPheaderInit(ip_header * ipheader);