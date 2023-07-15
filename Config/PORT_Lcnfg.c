/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			PORT_Lcnfg.c
 *  DESCRIPTION:	Configurations for PORT module -- TO BE MODIFIED BY USER
 *****************************************************************************/

 /** INCLUDES
 *****************************************************/
#include "PORT_cnfg.h"


 /** GLOBAL DATA
 *****************************************************/
 #if(PINS_USED)
PORT_config_t configPtr[PINS_USED] = {
	{PIN_F3, DIO, OUTPUT, PULL_DOWN, _2MA, NO_TRIGGER, NO_EDGE},
	{PIN_F4, DIO, INPUT, PULL_UP, NO_CURR, NO_TRIGGER, FALLING_EDGE},
	{PIN_F0, DIO, INPUT, PULL_UP, NO_CURR, NO_TRIGGER, FALLING_EDGE},
};

#else
PORT_config_t *configPtr;
#endif
  /** END OF FILE: PORT_Lcnfg.c
   *****************************************************/
