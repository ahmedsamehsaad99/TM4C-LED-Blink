/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			DIO.h
 *  DESCRIPTION:	Header file for the DIO driver
******************************************************************************/

#ifndef DIO_H_
#define DIO_H_

/** INCLUDES
*******************************************************/
#include "../PORT/PORT.h"


/** GLOBAL DATA TYPES AND STRUCTURES
*****************************************************/
typedef enum
{
	PORTA = GPIO_A, PORTB = GPIO_B, PORTC = GPIO_C, PORTD = GPIO_D, PORTF = GPIO_F, PORTE = GPIO_E
}PORT_t;


/** GLOBAL FUNCTION PROTOTYPES
*****************************************************/
void		DIO_setChannelValue(PORT_pin_t theChannel, uint8_t theValue);
uint8_t		DIO_getChannelValue(PORT_pin_t theChannel);
void		DIO_toggleChannel(PORT_pin_t theChannel);
void		DIO_setPortValue(PORT_t thePort, uint8_t theValue);
uint8_t		DIO_getPortValue(PORT_t thePort);


#endif

/** END OF FILE: DIO.h
*****************************************************/
