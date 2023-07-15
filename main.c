/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			main.c
 *  DESCRIPTION:	Main file for the project
 *****************************************************************************/

 /** INCLUDES
 *****************************************************/
#include "Application/application.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/Interrupts/interrupts.h"

 /** LOCAL FUNCTION PROTOTYPES
 *****************************************************/
 void main_init(void);


 /** LOCAL FUNCTIONS
 *****************************************************/
void main_init(void)
{
	PORT_init();
	INTERRUPT_init();
}

 /** GLOBAL FUNCTIONS
 *****************************************************/
int main()
{
	main_init();
	APP_start();
	return 0;
}



  /** END OF FILE: .c
   *****************************************************/