/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			interrupts_Lcnfg.c
 *  DESCRIPTION:	File for user config of interrupts
 *****************************************************************************/

 /** INCLUDES
 *****************************************************/
#include "interrupts_cnfg.h"

 /** GLOBAL DATA
 *****************************************************/
 #if(USED_INTERRUPTS)
INTERRUPT_config_t interruptConfig[USED_INTERRUPTS] = 
{
	{SysTick_Exc, 0}
	/*{TIMER0A, 0},*/
};
#else
INTERRUPT_config_t *interruptConfig;
#endif

  /** END OF FILE: interrupts_Lcnfg.c
   *****************************************************/
