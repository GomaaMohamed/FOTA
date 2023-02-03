/***************************************/
/* Author  :Gomaa                      */
/* Date    :13 Aug 2020                 */
/* Version :V01                        */
/***************************************/
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"

#include   "GPIO_interface.h"

#include   "SEVSEG_interface.h"
#include   "SEVSEG_private.h"
#include   "SEVSEG_config.h"
void SEVSEG_voidDisplayNum(u8 Copy_u8Port,u8 Copy_u8HalfPort,u8 Copy_u8Value)
{
#if     SEVSEG_TYPE  ==  COM_CATHODE
GPIO_voidSetHalfPortDirection(Copy_u8Port,Copy_u8HalfPort,GPIO_OUTPUT_2MHZ_PP);
GPIO_voidSetHalfPortValue(Copy_u8Port,Copy_u8HalfPort,~(Copy_u8Value));
#elif  SEVSEG_TYPE  ==  COM_ANODE
GPIO_voidSetHalfPortDirection(Copy_u8Port,Copy_u8HalfPort,GPIO_OUTPUT_2MHZ_PP);
GPIO_voidSetHalfPortValue(Copy_u8Port,Copy_u8HalfPort,Copy_u8Value);
#endif	
	
}