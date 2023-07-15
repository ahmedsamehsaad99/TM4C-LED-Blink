/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			SYSTICK.h
 *  DESCRIPTION:	Header file for the system timers
******************************************************************************/

#ifndef SYS_TICK_TYPES_H
#define SYS_TICK_TYPES_H


/** INCLUDES
*******************************************************/
#include "../../Common/bitwise_dataTypes.h"


/** GLOBAL CONSTANT MACROS
*******************************************************/
#define ENABLE 1
#define DISABLE 0



/** GLOBAL DATA TYPES AND STRUCTURES
*****************************************************/
typedef enum 
{
	SYSTICK_PIOSC,
	SYSTICK_SYSCLK
} SYSTICK_clockSource_t;

typedef struct 
{
	SYSTICK_clockSource_t clockSource;
	uint32_t sysTickValue;
	uint8_t notificationEnable;
	void (*callBackFn)();
} SYSTICK_config_t;


#endif

/** END OF FILE: .h
*****************************************************/
