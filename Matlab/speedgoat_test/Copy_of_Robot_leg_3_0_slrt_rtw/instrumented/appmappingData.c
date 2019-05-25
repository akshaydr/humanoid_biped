#include "slrtappmapping.h"
#include "./maps/Copy_of_Robot_leg_3_0.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <Copy_of_Robot_leg_3_0> */
		{ /* SignalMapInfo */
			Copy_of_Robot_leg_3_0_BIOMAP,
			Copy_of_Robot_leg_3_0_LBLMAP,
			Copy_of_Robot_leg_3_0_SIDMAP,
			Copy_of_Robot_leg_3_0_SBIO,
			Copy_of_Robot_leg_3_0_SLBL,
			{0,2483},
			901,
		},
		{ /* ParamMapInfo */
			Copy_of_Robot_leg_3_0_PTIDSMAP,
			Copy_of_Robot_leg_3_0_PTNAMESMAP,
			Copy_of_Robot_leg_3_0_SPTMAP,
			{0,348},
			349,
		},
		"Copy_of_Robot_leg_3_0",
		"",
		"Copy_of_Robot_leg_3_0",
		4,
		Copy_of_Robot_leg_3_0_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}