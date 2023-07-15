/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			LED.h
 *  DESCRIPTION:	Header file for the switch driver
******************************************************************************/

#ifndef SWITCH_H_
#define SWITCH_H_

/** INCLUDES
*******************************************************/
#include "../../MCAL/PORT/PORT.h"
#include "../../MCAL/DIO/DIO.h"


/** GLOBAL CONSTANT MACROS
*******************************************************/
#define SWITCH_1		PIN_F4
#define SWITCH_2		PIN_F0

/** GLOBAL FUNCTION MACROS
*******************************************************/


/** GLOBAL DATA TYPES AND STRUCTURES
*****************************************************/
typedef PORT_pin_t SWITCH_channel;


/** GLOBAL DATA PROTOTYPES
*****************************************************/


/** GLOBAL FUNCTION PROTOTYPES
*****************************************************/
uint8_t SWITCH_getValue(SWITCH_channel theSwitch);

#endif
/** END OF FILE: LED.h
*****************************************************/
