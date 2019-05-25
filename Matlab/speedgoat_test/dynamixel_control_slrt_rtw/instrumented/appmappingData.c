#include "slrtappmapping.h"
#include "./maps/dynamixel_control.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <dynamixel_control> */
		{ /* SignalMapInfo */
			dynamixel_control_BIOMAP,
			dynamixel_control_LBLMAP,
			dynamixel_control_SIDMAP,
			dynamixel_control_SBIO,
			dynamixel_control_SLBL,
			{0,3467},
			21,
		},
		{ /* ParamMapInfo */
			dynamixel_control_PTIDSMAP,
			dynamixel_control_PTNAMESMAP,
			dynamixel_control_SPTMAP,
			{0,24},
			25,
		},
		"dynamixel_control",
		"",
		"dynamixel_control",
		6,
		dynamixel_control_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}