/******************************************************************************
 *  FILE DESCRIPTION
 ---------------------------------------
 *  FILE:			bitwise_dataTypes.h
 *  DESCRIPTION:	Header file for the used data types as well as the bitwise operations
 *****************************************************************************/

#ifndef BITWISE_DATATYPES_H_
#define BITWISE_DATATYPES_H_

 /** GLOBAL MACROS
  *******************************************************/
#define HIGH 1
#define LOW 0

/** GLOBAL FUNCTION MACROS
 *******************************************************/
#define setBitState(REGISTER, BITNUM, BITSTATE) ((BITSTATE == 1) ? (REGISTER |= (1<<BITNUM)) : (REGISTER &= ~(1<<BITNUM)))
#define getBit(REGISTER, BITNUM) 				((REGISTER & (1<<BITNUM)) >> BITNUM)
#define toggleBit(REGISTER, BITNUM) 			(REGISTER ^= (1<<BITNUM))

#define setValue(REGISTER, BITNUM, VALUE)       (REGISTER |= (VALUE<<BITNUM))
#define clearValue(REGISTER, BITNUM, VALUE)     (REGISTER &= ~(VALUE<<BITNUM))
#define getValue(REGISTER, BITNUM, VALUE)       ((REGISTER & (VALUE<<BITNUM)) >> BITNUM)

/** GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************/

typedef unsigned char	uint8_t;
typedef signed char		int8_t;

typedef unsigned short	uint16_t;
typedef signed short	int16_t;

typedef unsigned int	uint32_t;
typedef signed int		int32_t;

typedef unsigned long	uint64_t;
typedef signed long	int64_t;

#endif

/** END OF FILE: bitwise_dataTypes.h
 *****************************************************/