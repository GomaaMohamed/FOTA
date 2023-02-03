/***************************************/
/* Author  :Gomaa                      */
/* Date    :14 Seb 2020                 */
/* Version :V01                        */
/***************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "STK_interface.h"
#include  "GPIO_interface.h"
#include  "RCC_interface.h"


#include  "STP_interface.h"
#include  "STP_private.h"
#include  "STP_config.h"

void STP_voidInit(void)
{
	  RCC_voidEnableClock(STP_PORT_AND_BUS);
	  STK_voidInit();

	  GPIO_voidSetPinDirection(STP_SHIFT_CLOCK_PIN,GPIO_OUTPUT_2MHZ_PP);
	  GPIO_voidSetPinDirection(STP_STORE_CLOCK_PIN,GPIO_OUTPUT_2MHZ_PP);
	  GPIO_voidSetPinDirection(STP_DATA_PIN ,GPIO_OUTPUT_2MHZ_PP);
	  GPIO_voidSetPinDirection(STP_SHIFT_RESET_PIN ,GPIO_OUTPUT_2MHZ_PP);
}

void STP_voidSendSyncronous(u8 Copy_u8DataToSend,u8 Copy_u8Mode)
{
	if( Copy_u8Mode == STP_ALL_DATA_MODE){
	SizeFlag++;
	volatile u8 Locale_u8Bit;
	for(s8 Locale_s8Counter = 7; Locale_s8Counter >= 0;Locale_s8Counter--)
	{
		/* Send Bit By Bit Starting from MSB */
		Locale_u8Bit = GET_BIT(Copy_u8DataToSend,Locale_s8Counter);\
		GPIO_voidSetPinValue(STP_DATA_PIN,Locale_u8Bit);
		/* Send Shift Clock */
		GPIO_voidSetPinValue(STP_SHIFT_CLOCK_PIN,GPIO_HIGH);
		STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(STP_SHIFT_CLOCK_PIN,GPIO_LOW);
		STK_voidSetBusyWait(1);
	}
        if(SizeFlag == STP_DATA_SIZE)
        {
        	/* Send Store Clock */
	    GPIO_voidSetPinValue(STP_STORE_CLOCK_PIN,GPIO_HIGH);
		STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(STP_STORE_CLOCK_PIN,GPIO_LOW);
		STK_voidSetBusyWait(1);
		SizeFlag = 0;
        }

	}
	else{

	    	volatile u8 Locale_u8Bit;
			for(s8 Locale_s8Counter = 7; Locale_s8Counter >= 0;Locale_s8Counter--)
			{
				/* Send Bit By Bit Starting from MSB */
				Locale_u8Bit = GET_BIT(Copy_u8DataToSend,Locale_s8Counter);\
				GPIO_voidSetPinValue(STP_DATA_PIN,Locale_u8Bit);
				/* Send Shift Clock */
				GPIO_voidSetPinValue(STP_SHIFT_CLOCK_PIN,GPIO_HIGH);
				STK_voidSetBusyWait(1);
				GPIO_voidSetPinValue(STP_SHIFT_CLOCK_PIN,GPIO_LOW);
				STK_voidSetBusyWait(1);
			}


		        	/* Send Store Clock */
			    GPIO_voidSetPinValue(STP_STORE_CLOCK_PIN,GPIO_HIGH);
				STK_voidSetBusyWait(1);
				GPIO_voidSetPinValue(STP_STORE_CLOCK_PIN,GPIO_LOW);
				STK_voidSetBusyWait(1);


	}
	
	
}
void STP_voidResetShiftRegister(void)
{
  GPIO_voidSetPinValue(STP_SHIFT_RESET_PIN,GPIO_LOW);

}
void STP_voidSetShiftRegister(void)
{
  GPIO_voidSetPinValue(STP_SHIFT_RESET_PIN,GPIO_HIGH);

}
