#include "slrtappmapping.h"
#include "./maps/test.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <test> */
		{ /* SignalMapInfo */
			test_BIOMAP,
			test_LBLMAP,
			test_SIDMAP,
			test_SBIO,
			test_SLBL,
			{0,0},
			1,
		},
		{ /* ParamMapInfo */
			test_PTIDSMAP,
			test_PTNAMESMAP,
			test_SPTMAP,
			{0,2},
			3,
		},
		"test",
		"",
		"test",
		1,
		test_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}