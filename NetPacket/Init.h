#pragma once
#include  "PublicLib.h"

int InitDev(pcap_if_t **d);
int FreeDev(pcap_if_t *alldevs);
int OpenDev(pcap_if_t **d, pcap_t **adhandle);
int GetDevHandle(pcap_t **adhandle);//直接调用此函数得到设备句柄即可