#include "slrtappmapping.h"
#include "./maps/udp_comm_test.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <udp_comm_test> */
		{ /* SignalMapInfo */
			udp_comm_test_BIOMAP,
			udp_comm_test_LBLMAP,
			udp_comm_test_SIDMAP,
			udp_comm_test_SBIO,
			udp_comm_test_SLBL,
			{0,281},
			28,
		},
		{ /* ParamMapInfo */
			udp_comm_test_PTIDSMAP,
			udp_comm_test_PTNAMESMAP,
			udp_comm_test_SPTMAP,
			{0,48},
			49,
		},
		"udp_comm_test",
		"",
		"udp_comm_test",
		4,
		udp_comm_test_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}