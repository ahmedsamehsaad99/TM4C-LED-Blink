/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			GPT.c
 *  DESCRIPTION:	C file for the general purpose timer
 *****************************************************************************/

 /** INCLUDES
 *****************************************************/
#include "GPT.h"
#include "GPT_types.h"


 /** GLOBAL DATA
 *****************************************************/
static void(*interruptHandler)() = NULL;


 /** GLOBAL FUNCTIONS
 *****************************************************/

void GPT_init(const GPT_config_t *configPtr)
{
	if (configPtr->GPT_maxTickCount <= 65535) // Less than 16 bits
	{
		setValue(REG(CORTEXM4_TIMER0_BASE + (configPtr->GPTchannel * 0x1000), GPTMCFG), 0, 4); // SET THE CONFIG TO 16BIT
	}
	else if (configPtr->GPT_maxTickCount > 65535)
	{
		setValue(REG(CORTEXM4_TIMER0_BASE + (configPtr->GPTchannel * 0x1000), GPTMCFG), 0, 0); // SET THE CONFIG TO 32BIT
	}

	// SET PRESCALER VALUE
	setValue(REG(CORTEXM4_TIMER0_BASE + (configPtr->GPTchannel * 0x1000), GPTMTAPR), 0, F_CPU/configPtr->GPT_tickFreq);
	
	switch (configPtr->GPT_mode)
	{
		case GPT_MODE_CONT:
			break;
		case GPT_MODE_ONE_SHOT:
			setValue(REG(CORTEXM4_TIMER0_BASE+(configPtr->GPTchannel * 0x1000), GPTMTAMR), 0, 0x1); // NORMAL MODE, DOWNCOUNT
			setBitState(REG(CORTEXM4_TIMER0_BASE, GPTMTAMR), 4, HIGH);
			break;
	}

	GPT_enableNotification(configPtr->GPTchannel);
	GPT_setCallBackFn(configPtr->callBackFn);
}

void GPT_disableNotification(GPT_channel_t theChannel)
{
	setBitState(REG(CORTEXM4_TIMER0_BASE + (theChannel * 0x1000), GPTMIMR), 0, LOW); // TO DISABLE TIMERA INT
}

void GPT_enableNotification(GPT_channel_t theChannel)
{
	setBitState(REG(CORTEXM4_TIMER0_BASE + (theChannel * 0x1000), GPTMIMR), 0, HIGH); // TO ENABLE TIMERA INT
}

void GPT_startTimer(GPT_channel_t theChannel, GPT_value_t theValue)
{
	setValue(REG(CORTEXM4_TIMER0_BASE + (theChannel * 0x1000), GPTMTAILR), 0, theValue); // SET INITIAL VALUE OF TIMER
	setBitState(REG(CORTEXM4_TIMER0_BASE + (theChannel * 0x1000), GPTMICR), 0, HIGH); // TO CLEAR TIMERA TIMEOUT FLAG
	setBitState(REG(CORTEXM4_TIMER0_BASE + (theChannel * 0x1000), GPTMCTL), 0, HIGH); // TO ENABLE TIMERA
}

void GPT_stopTimer(GPT_channel_t theChannel)
{
	setBitState(REG(CORTEXM4_TIMER0_BASE + (theChannel * 0x1000), GPTMCTL), 0, LOW); // TO DISABLE TIMERA
}

uint32_t GPT_getElapsedTime(GPT_channel_t theChannel)
{
	uint32_t currentTicks = REG(CORTEXM4_TIMER0_BASE + (theChannel * 0x1000), GPTMTAV);
	return currentTicks;
}
uint32_t GPT_getRemainingTime(GPT_channel_t theChannel)
{
	uint32_t currentTicks = REG(CORTEXM4_TIMER0_BASE + (theChannel * 0x1000), GPTMTAV);
	uint32_t setTicks = REG(CORTEXM4_TIMER0_BASE + (theChannel * 0x1000), GPTMTAILR);

	return setTicks - currentTicks;
}

void GPT_setCallBackFn(void(*callBackFn)())
{
	interruptHandler = callBackFn;
}

void GPT_handler(void)
{
	(*interruptHandler)();
}


  /** END OF FILE: GPT.c
   *****************************************************/
