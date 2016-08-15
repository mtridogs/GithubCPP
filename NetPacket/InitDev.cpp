#include "Init.h"


/**********************************************/
/**********************************************/
/**********************************************/
int InitDev(pcap_if_t **d)//获取设备地址
{
	pcap_if_t *alldevs;
	int i = 0;
	int inum;
	pcap_t *adhandle;
	char errbuf[PCAP_ERRBUF_SIZE];


	if (pcap_findalldevs(&alldevs, errbuf) == -1)
	{
		printf("Could not find Computer Dev!\n");
		printf("[!]Error:%s\n", errbuf);
		return Fun_NotNormal;
	}

	for (*d = alldevs; *d != NULL;*d = (*d)->next)
	{
		printf("%d. %s", ++i, (*d)->name);
		if ((*d)->description)
			printf(" (%s)\n", (*d)->description);
		else
			printf(" (No Pcap!)\n");
	}

	if (i == 0)
	{
		printf("\nNo interfaces found!Check Your Computer!\n");
		return Fun_NotNormal;
	}

		printf("Enter the interface number (1-%d):", i);
		scanf("%d", &inum);

	if (inum < 1 || inum > i)
	{
		printf("\nInterface number out of range.\n");
		FreeDev(alldevs);
		return Fun_NotNormal;
	}

	for (*d = alldevs, i = 0; i< inum - 1; *d = (*d)->next, i++);

	return Fun_Normal;
}
/**********************************************/
/**********************************************/
/**********************************************/
int FreeDev(pcap_if_t *alldevs)//释放设备占用
{
	pcap_freealldevs(alldevs);
	return Fun_Normal;
}
/**********************************************/
/**********************************************/
/**********************************************/
int OpenDev(pcap_if_t **d, pcap_t **adhandle)
{
	char errbuf[PCAP_ERRBUF_SIZE];

	if ((*adhandle = pcap_open_live((*d)->name/*设备名*/, 65536/*大小*/, 1/*模式*/, 1000/*超时时间*/, errbuf)) == NULL)
	{
		fprintf(stderr, "\nOpenDEV Fail. %s Maybe is a bad Dev!\n",(*d)->name);
		pcap_freealldevs((*d));
		return Fun_NotNormal;
	}

	printf("Dev Interface is Ok!\n");
	return Fun_Normal;
}
/**********************************************/
/**********************************************/
/**********************************************/
int GetDevHandle(pcap_t **devhandle)
{
	pcap_if_t *d =NULL;
	if(InitDev(&d) == Fun_NotNormal)
	{
		printf("Interface Open Fail!\n");
		return 0;
	}

	if (OpenDev(&d,devhandle)==Fun_NotNormal)
	{
		printf("Interface Open Fail!\n");
		return 0;
	}
	return Fun_Normal;
}