/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			PORT.h
 *  DESCRIPTION:	Header file for the PORT module
******************************************************************************/

#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_

/** INCLUDES
*******************************************************/
#include "../../Common/registers.h"
#include "../../Common/bitwise_dataTypes.h"


/** GLOBAL DATA TYPES AND STRUCTURES
*****************************************************/

typedef enum {
	PIN_A0,
	PIN_A1,
	PIN_A2,
	PIN_A3,
	PIN_A4,
	PIN_A5,
	PIN_A6,
	PIN_A7,

	PIN_B0,
	PIN_B1,
	PIN_B2,
	PIN_B3,
	PIN_B4,
	PIN_B5,
	PIN_B6,
	PIN_B7,

	PIN_C0,
	PIN_C1,
	PIN_C2,
	PIN_C3,
	PIN_C4,
	PIN_C5,
	PIN_C6,
	PIN_C7,

	PIN_D0,
	PIN_D1,
	PIN_D2,
	PIN_D3,
	PIN_D4,
	PIN_D5,
	PIN_D6,
	PIN_D7,

	PIN_E0,
	PIN_E1,
	PIN_E2,
	PIN_E3,
	PIN_E4,
	PIN_E5,
	PIN_E6,
	PIN_E7,

	PIN_F0,
	PIN_F1,
	PIN_F2,
	PIN_F3,
	PIN_F4,
	PIN_F5,
	PIN_F6,
	PIN_F7
} PORT_pin_t;

typedef enum {
	INPUT, OUTPUT
} PORT_direction_t;

typedef enum {
	DIO, EXT_INT, ADC, DMA, ANALOG, OTH
} PORT_mode_t;

typedef enum {
	NO_ATT, PULL_UP, PULL_DOWN, OPEN_DRAIN
} PORT_attachement_t;

typedef enum {
	NO_CURR, _2MA, _4MA, _8MA
} PORT_current_t;

typedef enum {
	NO_EDGE, LOW_EDGE, HIGH_EDGE, FALLING_EDGE, RISING_EDGE
} PORT_edge_t;

typedef enum {
	NO_TRIGGER, LEVEL_TRIGGER, SINGLE_EDGE_TRIGGER, BOTH_EDGES_TRIGGER
} PORT_intTrigger_t;

typedef struct {
	PORT_pin_t PIN;
	PORT_mode_t PIN_mode;
	PORT_direction_t PIN_direction;
	PORT_attachement_t PIN_attachement;
	PORT_current_t PIN_current;
	PORT_intTrigger_t PIN_interruptTrigg;
	PORT_edge_t PIN_edge;
} PORT_config_t;


#endif
/** END OF FILE: PORT_types.h
*****************************************************/
