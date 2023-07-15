/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			DIO.c
 *  DESCRIPTION:	C file for the DIO driver
 *****************************************************************************/

 /** INCLUDES
 *****************************************************/
#include "DIO.h"


uint32_t PORTS[6] = { GPIO_A, GPIO_B, GPIO_C, GPIO_D, GPIO_E, GPIO_F };


 /** GLOBAL FUNCTIONS
 *****************************************************/

void DIO_setChannelValue(PORT_pin_t theChannel, uint8_t theValue)
{
	uint32_t currentPort = PORTS[theChannel / 8];
	uint8_t	 currentPin = theChannel % 8;

	if (theValue == LOW)
		setBitState(REG(currentPort, GPIODATA), currentPin, LOW);
	else
		setBitState(REG(currentPort, GPIODATA), currentPin, HIGH);
}

uint8_t	DIO_getChannelValue(PORT_pin_t theChannel)
{
	uint32_t currentPort = PORTS[theChannel / 8]; // TO GET THE CURRENT PORT, DIVIDE THE PIN/8
	uint8_t	 currentPin = theChannel % 8; // TO GET THE CURRENT PIN, REMAINDER OF 8

	return (getBit(REG(currentPort, GPIODATA), currentPin));
}

void DIO_toggleChannel(PORT_pin_t theChannel)
{
	uint32_t currentPort = PORTS[theChannel / 8]; // TO GET THE CURRENT PORT, DIVIDE THE PIN/8
	uint8_t	 currentPin = theChannel % 8; // TO GET THE CURRENT PIN, REMAINDER OF 8

	toggleBit(REG(currentPort, GPIODATA), currentPin);
}

void DIO_setPortValue(PORT_t thePort, uint8_t theValue)
{
	REG(thePort, GPIODATA) = theValue;
}

uint8_t	DIO_getPortValue(PORT_t thePort)
{
	return getBit(thePort, GPIODATA);
}

  /** END OF FILE: DIO.c
   *****************************************************/
