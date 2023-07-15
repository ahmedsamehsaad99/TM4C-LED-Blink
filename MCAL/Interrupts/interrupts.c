/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			INTERRUPTS.c
 *  DESCRIPTION:	C file for the interrupts handler
 *****************************************************************************/

 /** INCLUDES
 *****************************************************/
#include "interrupts.h"
#include "../../Common/registers.h"
#include "../../Config/interrupts_cnfg.h"


 /** GLOBAL DATA
 *****************************************************/
extern INTERRUPT_config_t interruptConfig[];

 /** GLOBAL FUNCTIONS
 *****************************************************/
void INTERRUPT_init(void)
{
	REG(CORTEXM4_PERIPHERAL_BASE, APINT) = (0x05FA0000U | (PRIORITY_LEVEL << 8));
	
	uint8_t i;
	
	for (i = 0; i < USED_INTERRUPTS; i++)
	{
		if (interruptConfig[i].interruptType < 16) // FOR EXCEPTIONS
		{
			if (interruptConfig[i].interruptType <= 6); // SYSPRI1
			else if (interruptConfig[i].interruptType <= 11);		// SYSPRI2
			else if (interruptConfig[i].interruptType <= 15)	// SYSPRI3
			{
				if (interruptConfig[i].interruptType == 15) // SysTick
				{
					setValue(REG(CORTEXM4_PERIPHERAL_BASE, SYSPRI3), 29, interruptConfig[i].priority);
					setBitState(REG(CORTEXM4_PERIPHERAL_BASE, SYSHNDCTRL), 11, HIGH); // System Tick ON
				}
			}
		}
		else
		{
			interruptConfig[i].interruptType -= 16;
			setValue(REG(CORTEXM4_PERIPHERAL_BASE, PRI0 + ((interruptConfig[i].interruptType/4)*4)), ((interruptConfig[i].interruptType % 4) * 8) + 5, interruptConfig[i].priority);
			setBitState(REG(CORTEXM4_PERIPHERAL_BASE, EN0 + (interruptConfig[i].interruptType/32)*4), interruptConfig[i].interruptType % 32, HIGH);
		}
	}
}
  /** END OF FILE: .c
   *****************************************************/
