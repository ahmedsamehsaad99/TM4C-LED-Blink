/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			registers.h
 *  DESCRIPTION:	Header file for the used registers addresses
 *****************************************************************************/

#ifndef REGISTERS_H_
#define REGISTERS_H_

/** INCLUDES
 *******************************************************/
#include "bitwise_dataTypes.h"


/** GLOBAL CONSTANT MACROS
 *******************************************************/
#define F_CPU							16000000UL
#define NULL							((void*)0)

#define REG(BASE, OFFSET)				*((volatile uint32_t*)(BASE+OFFSET))

#define	CORTEXM4_SYSTEM_CONTROL_BASE	(0x400FE000)
#define CORTEXM4_PERIPHERAL_BASE		(0xE000E000)

#define CORTEXM4_TIMER0_BASE			(0x40030000)
#define CORTEXM4_TIMER1_BASE			(0x40031000)
#define CORTEXM4_TIMER2_BASE			(0x40032000)
#define CORTEXM4_TIMER3_BASE			(0x40033000)
#define CORTEXM4_TIMER4_BASE			(0x40034000)
#define CORTEXM4_TIMER5_BASE			(0x40035000)

#define CORTEXM4_TIMER0_WIDE_BASE		(0x40036000)
#define CORTEXM4_TIMER1_WIDE_BASE		(0x40037000)
#define CORTEXM4_TIMER2_WIDE_BASE		(0x4004C000)
#define CORTEXM4_TIMER3_WIDE_BASE		(0x4004D000)
#define CORTEXM4_TIMER4_WIDE_BASE		(0x4004E000)
#define CORTEXM4_TIMER5_WIDE_BASE		(0x4004F000)

#define STCTRL							(0x010)
#define STRELOAD						(0x014)
#define STCURRENT						(0x018)


#define GPTMTAMR						(0x004)
#define GPTMTBMR						(0x008)
#define GPTMCFG							(0x000)
#define GPTMTAPR						(0x038)
#define GPTMCTL							(0x00C)
#define GPTMTAILR						(0x028)
#define GPTMIMR							(0x018)
#define GPTMICR							(0x024)
#define GPTMTAV							(0x050)

#define PRI0							(0x400)
#define EN0								(0x100)

#define SYSPRI1							(0xD18)
#define SYSPRI2							(0xD1C)
#define SYSPRI3							(0xD20)

#define SYSHNDCTRL						(0xD24)


#define RCGCGPIO						(0x608)

#define GPIO_A							(0x40004000)
#define GPIO_B							(0x40005000)
#define GPIO_C							(0x40006000)
#define GPIO_D							(0x40007000)
#define GPIO_E						    (0x40024000)
#define GPIO_F						    (0x40025000)

#define GPIODATA						(0x3FC)
#define GPIODIR							(0x400)
#define GPIOIS							(0x404)
#define GPIOIBE							(0x408)
#define GPIOIEV						    (0x40C)
#define GPIOIM							(0x410)
#define GPIORIS				            (0x414)
#define GPIOMIS					        (0x418)
#define GPIOICR					        (0x41C)
#define GPIOAFSEL		                (0x420)
#define GPIODR2R			            (0x500)
#define GPIODR4R				        (0x504)
#define GPIODR8R					    (0x508)
#define GPIOODR	                        (0x50C)
#define GPIOPUR		                    (0x510)
#define GPIOPDR                         (0x514)
#define GPIOSLR					        (0x518)
#define GPIODEN						    (0x51C)
#define GPIOLOCK						(0x520)
#define GPIOCR					        (0x524)
#define GPIOAMSEL						(0x528)
#define GPIOPCTL						(0x52C)
#define GPIOADCCTL						(0x530)
#define GPIODMACTL						(0x534)

#define APINT							(0xD0C)

#endif
 /** END OF FILE: .h
 *****************************************************/