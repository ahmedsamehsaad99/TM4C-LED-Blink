/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			registers.h
 *  DESCRIPTION:	Header file for the used registers addresses
******************************************************************************/

#ifndef GPT_TYPES_H_
#define GPT_TYPES_H_

/** INCLUDES
*******************************************************/
#include "../../Common/bitwise_dataTypes.h"


/** GLOBAL DATA TYPES AND STRUCTURES
*****************************************************/
typedef enum {
	TIMER0, TIMER1, TIMER2, TIMER3, TIMER4, TIMER5, TIMER6, TIMER7, TIMER8, TIMER9, TIMER10, TIMER11
}GPT_channel_t;

typedef uint32_t GPT_value_t;

typedef enum {
	GPT_MODE_CONT, GPT_MODE_ONE_SHOT
}GPT_mode_t;

typedef enum {
	GPT_PREDEF_TIMER_1US_16BIT,
	GPT_PREDEF_TIMER_1US_24BIT,
	GPT_PREDEF_TIMER_1US_32BIT,
	GPT_PREDEF_TIMER_100US_32BIT
}GPT_predefTimer_t;

typedef struct {
	GPT_channel_t GPTchannel;
	uint32_t GPT_tickFreq;
	uint32_t GPT_maxTickCount;
	GPT_mode_t GPT_mode;
	void(*callBackFn)();
}GPT_config_t;



#endif

/** END OF FILE: .h
*****************************************************/
