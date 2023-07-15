/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			SYSTICK.h
 *  DESCRIPTION:	Header file for the system timers
******************************************************************************/

#ifndef SYS_TICK_H
#define SYS_TICK_H

/** INCLUDES
*******************************************************/
#include "../../Common/registers.h"
#include "systick_types.h"


/** GLOBAL FUNCTION MACROS
*******************************************************/
void SYSTICK_init(const SYSTICK_config_t *config);
void SYSTICK_enableNotification(void);
void SYSTICK_disableNotification(void);
void SYSTICK_reloadValue(uint32_t theValue);
uint32_t SYSTICK_getValue(void);
uint8_t SYSTICK_getFlagStatus(void);
void SYSTICK_startTimer(void);
void SYSTICK_stopTimer(void);
void SYSTICK_setCallbackFunction(void(*callBackFn)());
void SysTick_Handler(void);

#endif

/** END OF FILE: .h
*****************************************************/
