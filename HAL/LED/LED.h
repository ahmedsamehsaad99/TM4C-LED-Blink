/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			LED.h
 *  DESCRIPTION:	Header file for the LED driver
******************************************************************************/

#ifndef LED_H_
#define LED_H_

/** INCLUDES
*******************************************************/
#include "../../MCAL/PORT/PORT_types.h"
#include "../../MCAL/PORT/PORT.h"
#include "../../MCAL/DIO/DIO.h"


/** GLOBAL CONSTANT MACROS
*******************************************************/
#define GREEN_LED		PIN_F3

/** GLOBAL FUNCTION MACROS
*******************************************************/


/** GLOBAL DATA TYPES AND STRUCTURES
*****************************************************/
typedef PORT_pin_t LED_channel;


/** GLOBAL DATA PROTOTYPES
*****************************************************/


/** GLOBAL FUNCTION PROTOTYPES
*****************************************************/
void LED_turnOn(LED_channel theLED);
void LED_turnOff(LED_channel theLED);
void LED_toggle(LED_channel theLED);


#endif
/** END OF FILE: LED.h
*****************************************************/
