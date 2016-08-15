#pragma once
#include "PublicLib.h"
#include "Init.h"


int SendPacketTo(pcap_t **adhandle, u_char *PacketData, int PacketDataLength);
