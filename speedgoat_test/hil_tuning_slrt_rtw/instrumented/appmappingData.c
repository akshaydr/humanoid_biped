#include "slrtappmapping.h"
#include "./maps/hil_tuning.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <hil_tuning> */
		{ /* SignalMapInfo */
			hil_tuning_BIOMAP,
			hil_tuning_LBLMAP,
			hil_tuning_SIDMAP,
			hil_tuning_SBIO,
			hil_tuning_SLBL,
			{0,365},
			112,
		},
		{ /* ParamMapInfo */
			hil_tuning_PTIDSMAP,
			hil_tuning_PTNAMESMAP,
			hil_tuning_SPTMAP,
			{0,102},
			103,
		},
		"hil_tuning",
		"",
		"hil_tuning",
		3,
		hil_tuning_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}