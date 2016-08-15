#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <pcap.h>
#include <stdint.h>


#define Fun_Normal 0
#define Fun_NotNormal -1

void test();
uint32_t  crc32(const unsigned char *buf, uint32_t  size);

USHORT crc16(UCHAR * pucFrame, USHORT usLen);