/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			interrupts_types.h
 *  DESCRIPTION:	Header file for types of interrupts
******************************************************************************/

#ifndef INTERRUPTS_TYPES_H
#define INTERRUPTS_TYPES_H

/** INCLUDES
*******************************************************/
#include "../../Common/registers.h"
#include "../../Common/bitwise_dataTypes.h"

/** GLOBAL DATA TYPES AND STRUCTURES
*****************************************************/

typedef enum {
	XXX,
	XXY = 5,
	XYY,
	YYY
}INTERRUPT_priorityLevel_t;

typedef enum {
	SysTick_Exc = 15,
	TIMER0A = 35
} INTERRUPT_type_t;

typedef struct {
	INTERRUPT_type_t interruptType;
	uint8_t priority;
} INTERRUPT_config_t;


#endif

/** END OF FILE: interrupts_types.h
*****************************************************/
