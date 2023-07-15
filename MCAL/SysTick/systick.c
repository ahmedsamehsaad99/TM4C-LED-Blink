/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			systick.c
 *  DESCRIPTION:	C file for the Systick peripheral
 *****************************************************************************/

 /** INCLUDES
 *****************************************************/
#include "systick.h"


 /** LOCAL DATA
 *****************************************************/
static void(*interrupt_handler)() = NULL;



 /** GLOBAL FUNCTIONS
 *****************************************************/
void SYSTICK_init(const SYSTICK_config_t *config)
{
	SYSTICK_stopTimer();

	switch (config->clockSource) 
	{
		case SYSTICK_PIOSC:
			setBitState(REG(CORTEXM4_PERIPHERAL_BASE, STCTRL), 2, LOW);
			break;

		case SYSTICK_SYSCLK:
			setBitState(REG(CORTEXM4_PERIPHERAL_BASE, STCTRL), 2, HIGH);
			break;
	}

	if (config->notificationEnable == ENABLE)
		SYSTICK_enableNotification();
	
	SYSTICK_reloadValue(config->sysTickValue);
	SYSTICK_setCallbackFunction(config->callBackFn);
}

void SYSTICK_enableNotification(void)
{
	setBitState(REG(CORTEXM4_PERIPHERAL_BASE, STCTRL), 1, HIGH);
}

void SYSTICK_disableNotification(void)
{
	setBitState(REG(CORTEXM4_PERIPHERAL_BASE, STCTRL), 1, LOW);
}

void SYSTICK_reloadValue(uint32_t theValue)
{
	REG(CORTEXM4_PERIPHERAL_BASE, STRELOAD) = theValue;
	REG(CORTEXM4_PERIPHERAL_BASE, STCURRENT) = 1;
}

uint32_t SYSTICK_getValue(void)
{
	return REG(CORTEXM4_PERIPHERAL_BASE, STCURRENT);
}

uint8_t SYSTICK_getFlagStatus(void)
{
	return getBit(REG(CORTEXM4_PERIPHERAL_BASE, STCTRL), 16);
}

void SYSTICK_startTimer(void)
{
	setBitState(REG(CORTEXM4_PERIPHERAL_BASE, STCTRL), 0, HIGH);
}
void SYSTICK_stopTimer(void)
{
	setBitState(REG(CORTEXM4_PERIPHERAL_BASE, STCTRL), 0, LOW);
}

void SYSTICK_setCallbackFunction(void(*callBackFn)())
{
	interrupt_handler = callBackFn;
}

void SysTick_Handler(void)
{
	(*interrupt_handler)();
}


  /** END OF FILE: .c
   *****************************************************/
