/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			application.c
 *  DESCRIPTION:	Application layer for the project
 *****************************************************************************/

 /** INCLUDES
 *****************************************************/
#include "application.h"

 /** LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************/


 /** LOCAL DATA
 *****************************************************/
volatile static uint8_t SECONDS = 0;
volatile static uint8_t CONFIRMED = 0;


 /** LOCAL FUNCTION PROTOTYPES
 *****************************************************/
void delay_ISR(void);

 /** LOCAL FUNCTIONS
 *****************************************************/
void delay_ISR(void)
{				
	SECONDS++;
}

 /** GLOBAL FUNCTIONS
 *****************************************************/
void APP_start(void)
{
	delay_init(delay_ISR);
	volatile static uint8_t PRESSES = 0;
	
	while (1)
	{
		if (SWITCH_getValue(SWITCH_1) == LOW)
		{
			if (CONFIRMED == 0 || PRESSES == 0)
			{
				CONFIRMED = 0;
				PRESSES++;
			}
			else
				PRESSES = 0;
		}
		
		if (SWITCH_getValue(SWITCH_2) == LOW) /*CONFIRMATION SWITCHS*/
		{
				CONFIRMED = 1;
				delay_ms(1000);
		}
		
		if (SECONDS == PRESSES && PRESSES != 0)
		{
				LED_toggle(GREEN_LED);
				SECONDS = 0;
		}
	}
}


  /** END OF FILE: .c
   *****************************************************/
