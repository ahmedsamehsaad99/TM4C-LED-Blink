/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			LED.c
 *  DESCRIPTION:	C file for the LED HAL
 *****************************************************************************/

 /** INCLUDES
 *****************************************************/
#include "LED.h"

 /** LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************/


 /** LOCAL DATA
 *****************************************************/


 /** GLOBAL DATA
 *****************************************************/

 /** LOCAL FUNCTION PROTOTYPES
 *****************************************************/

 /** LOCAL FUNCTIONS
 *****************************************************/

 /** GLOBAL FUNCTIONS
 *****************************************************/
void LED_turnOn(LED_channel theLED)
{
	DIO_setChannelValue(theLED, HIGH);
}

void LED_turnOff(LED_channel theLED)
{
	DIO_setChannelValue(theLED, LOW);
}

void LED_toggle(LED_channel theLED)
{
	DIO_toggleChannel(theLED);
}


  /** END OF FILE: .c
   *****************************************************/
