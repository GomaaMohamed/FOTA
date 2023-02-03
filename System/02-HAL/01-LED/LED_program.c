/***************************************/
/* Author  :Gomaa                      */
/* Date    :13 Aug 2020                 */
/* Version :V01                        */
/***************************************/

#include   "STD_TYPES.h"
#include   "BIT_MATH.h"

#include   "GPIO_interface.h"

#include   "LED_interface.h"
#include   "LED_private.h"
#include   "LED_config.h"

void LED_voidOn(u8 Copy_u8Port,u8 Copy_u8Pin)
{
GPIO_voidSetPinDirection(Copy_u8Port,Copy_u8Pin,GPIO_OUTPUT_2MHZ_PP);
GPIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin,GPIO_HIGH);
}
void LED_voidOff(u8 Copy_u8Port,u8 Copy_u8Pin)
{
GPIO_voidSetPinDirection(Copy_u8Port,Copy_u8Pin,GPIO_OUTPUT_2MHZ_PP);
GPIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin,GPIO_LOW);	
}