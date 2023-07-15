/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			delay.h
 *  DESCRIPTION:	Header file for the delay service layer
******************************************************************************/

#ifndef DELAY_H_
#define DELAY_H_

/** INCLUDES
*******************************************************/
/*#include "../../MCAL/GPT/GPT_types.h"
#include "../../MCAL/GPT/GPT.h"
*/
#include "../../MCAL/SysTick/systick.h"

/** GLOBAL FUNCTION PROTOTYPES
*****************************************************/
void delay_init(void(*callBackFn)());
void delay_ms(uint32_t milliseconds);


#endif

/** END OF FILE: .h
*****************************************************/
