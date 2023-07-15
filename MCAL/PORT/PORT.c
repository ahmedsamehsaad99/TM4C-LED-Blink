/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			PORT.c
 *  DESCRIPTION:	C file for the PORT module
 *****************************************************************************/

 /** INCLUDES
 *****************************************************/
#include "PORT.h"
#include "../../Config/PORT_cnfg.h"


 /** GLOBAL DATA
 *****************************************************/
extern PORT_config_t configPtr[];	// Getting the configuartions made by the user

 /** GLOBAL FUNCTIONS
 *****************************************************/


 /******************************************************************************
  * Syntax          : void PORT_init()
  * Description     : To configure GPIO pins
  * Sync/Async      : Sync
  * Reentrancy      : Non-Reentrant
  * Parameters (in) : None
  * Parameters (out): None
  * Return value    : None
  *****************************************************************************/

void PORT_init(void)
{
	uint32_t PORTS[6] = { GPIO_A, GPIO_B, GPIO_C, GPIO_D, GPIO_E, GPIO_F };
	uint8_t i;
	for (i = 0; i < PINS_USED; i++) // LOOP THROUGH ALL USED PINS
	{
		setBitState(REG(CORTEXM4_SYSTEM_CONTROL_BASE, RCGCGPIO), configPtr[i].PIN / 8, HIGH);	// ENABLE CLOCK

		uint32_t currentPort = PORTS[configPtr[i].PIN / 8]; // TO GET THE CURRENT PORT, DIVIDE THE PIN/8
		uint8_t	 currentPin = configPtr[i].PIN % 8; // TO GET THE CURRENT PIN, REMAINDER OF 8

		// TO SET PIN MODE CONFIGURATIONS
		switch (configPtr[i].PIN_mode)
		{
			case DIO:
				setBitState(REG(currentPort, GPIODEN), currentPin, HIGH);
				break;

			case EXT_INT:
				setBitState(REG(currentPort, GPIODIR), currentPin, LOW);
				setBitState(REG(currentPort, GPIODEN), currentPin, HIGH);
				setBitState(REG(currentPort, GPIOIM), currentPin, LOW);

				switch (configPtr[i].PIN_interruptTrigg) 
				{
					case LEVEL_TRIGGER:
						setBitState(REG(currentPort, GPIOIS), currentPin, HIGH);
						break;

					case SINGLE_EDGE_TRIGGER:
						setBitState(REG(currentPort, GPIOIS), currentPin, LOW);
						setBitState(REG(currentPort, GPIOIBE), currentPin, LOW);
						break;

					case BOTH_EDGES_TRIGGER:
						setBitState(REG(currentPort, GPIOIS), currentPin, LOW);
						setBitState(REG(currentPort, GPIOIBE), currentPin, HIGH);
						break;

					default:
						break;
				}

				switch (configPtr[i].PIN_edge) 
				{
					case RISING_EDGE:
						setBitState(REG(currentPort, GPIOIEV), currentPin, HIGH);
						break;

					case FALLING_EDGE:
						setBitState(REG(currentPort, GPIOIEV), currentPin, LOW);
						break;

					default:
						break;
				}
				break;
		}

		// TO SET PIN DIRECTION FROM USER CONFIG
		switch (configPtr[i].PIN_direction) 
		{
			case INPUT:
				setBitState(REG(currentPort, GPIODIR), currentPin, LOW);
				break;

			case OUTPUT:
				setBitState(REG(currentPort, GPIODIR), currentPin, HIGH);

				switch (configPtr[i].PIN_current)
				{
					case _2MA:
						setBitState(REG(currentPort, GPIODR2R), currentPin, HIGH);
						break;

					case _4MA:
						setBitState(REG(currentPort, GPIODR4R), currentPin, HIGH);
						break;

					default:
						break;
				}
				break;
		}

		// TO SET INTERNAL ATTACHEMENT, PULL UP/DOWN RESISTOR OR OPEN DRAIN OR NONE
		switch (configPtr[i].PIN_attachement) 
		{
			case PULL_UP:
				setBitState(REG(currentPort, GPIOPUR), currentPin, HIGH);
				break;

			case PULL_DOWN:
				setBitState(REG(currentPort, GPIOPDR), currentPin, HIGH);
				break;

			case OPEN_DRAIN:
				setBitState(REG(currentPort, GPIOODR), currentPin, HIGH);
				break;

			default:
				break;
		}
	}
}

  /** END OF FILE: PORT.c
   *****************************************************/