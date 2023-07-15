/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			GPT.h
 *  DESCRIPTION:	Header file for the General Purpose Timers
******************************************************************************/

#ifndef GPT_H_
#define GPT_H_

/** INCLUDES
*******************************************************/
#include "../../Common/bitwise_dataTypes.h"
#include "../../Common/registers.h"
#include "GPT_types.h"

/** GLOBAL CONSTANT MACROS
*******************************************************/


/** GLOBAL FUNCTION MACROS
*******************************************************/


/** GLOBAL DATA TYPES AND STRUCTURES
*****************************************************/

/** GLOBAL DATA PROTOTYPES
*****************************************************/


/** GLOBAL FUNCTION PROTOTYPES
*****************************************************/
void GPT_init(const GPT_config_t *configPtr);
void GPT_disableNotification(GPT_channel_t theChannel);
void GPT_enableNotification(GPT_channel_t theChannel);
void GPT_startTimer(GPT_channel_t theChannel, GPT_value_t theValue);
void GPT_stopTimer(GPT_channel_t theChannel);
void GPT_setCallBackFn(void(*callBackFn)());
void GPT_handler(void);
uint32_t GPT_getElapsedTime(GPT_channel_t theChannel);
uint32_t GPT_getRemainingTime(GPT_channel_t theChannel);


#endif

/** END OF FILE: .h
*****************************************************/
