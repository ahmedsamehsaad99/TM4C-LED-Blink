/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			delay.c
 *  DESCRIPTION:	C file for the delay service layer
 *****************************************************************************/

 /** INCLUDES
 *****************************************************/
#include "delay.h"

 /** LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************/
 /** LOCAL FUNCTION PROTOTYPES
 *****************************************************/

 /** LOCAL DATA
 *****************************************************/
/*uint8_t timeouts = 0;*/

 /** GLOBAL DATA
 *****************************************************/
/*GPT_config_t theConfiguration =
{
	// timer, required freq, max ticks, mode, callback
	TIMER0, 65573, 65535, GPT_MODE_ONE_SHOT, delay_ISR
};
*/



 /** LOCAL FUNCTIONS
 *****************************************************/


 /** GLOBAL FUNCTIONS
 *****************************************************/
void delay_init(void (*callBackFn)())
{
	SYSTICK_config_t config =
	{
		SYSTICK_SYSCLK, 0, ENABLE, callBackFn
	};

	SYSTICK_init(&config);
}

void delay_ms(uint32_t milliseconds)
{
	SYSTICK_reloadValue(16 * 1000 * milliseconds);
	SYSTICK_startTimer();
}
/*void delay_ms(uint32_t milliseconds)
{
	GPT_init(&theConfiguration);
	
	uint8_t neededTimeouts = (milliseconds / 1000) + 1;
	uint16_t startValue = 65535 * (milliseconds%1000) / 1000;

	GPT_startTimer(theConfiguration.GPTchannel, startValue); // Downcounting with the following presscaler results in 1 second

	while (timeouts <= neededTimeouts);

	timeouts = 0;
	GPT_stopTimer(theConfiguration.GPTchannel);
}
*/


  /** END OF FILE: delay.c
   *****************************************************/
