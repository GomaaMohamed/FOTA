/***************************************/
/* Author  :Gomaa                      */
/* Date    :31 Aug 2020                 */
/* Version :V01                        */
/***************************************/

#include   "STD_TYPES.h"
#include   "BIT_MATH.h"

#include   "STP_interface.h"
#include   "STK_interface.h"

#include   "LEDMRX_interface.h"
#include   "LEDMRX_private.h"
#include   "LEDMRX_config.h"

void LEDMRX_voidInit(void)
{
STP_voidInit();

}
static void DisableAllCols(void)
{
	    STP_voidSendSyncronous(0b11111111,STP_ALL_DATA_MODE);
	    STP_voidSendSyncronous(0b11111111,STP_ALL_DATA_MODE);
}
void LEDMRX_voidDisplay(u8 *Copy_u8Data)
{

for(u8 i = 0; i<= 25 ;i++){
	DisableAllCols();
	/* Send and Set The Row */
    STP_voidSendSyncronous(Copy_u8Data[0],STP_SINGLE_BYTE_MODE);
    /* Send The Coulmn & Row and Set Coloumn 0 */
    STP_voidSendSyncronous(0b11111110,STP_ALL_DATA_MODE);
    STP_voidSendSyncronous(Copy_u8Data[0],STP_ALL_DATA_MODE);
    /* Make a delay by 1300 Ms */
	STK_voidSetBusyWait(1300);
	
	DisableAllCols();
	/* Send The Row */
	    STP_voidSendSyncronous(Copy_u8Data[1],STP_SINGLE_BYTE_MODE);
	    /* Send The Coulmn & Row */
	STP_voidSendSyncronous(0b11111101,STP_ALL_DATA_MODE);
	STP_voidSendSyncronous(Copy_u8Data[1],STP_ALL_DATA_MODE);
    STK_voidSetBusyWait(1300);

    DisableAllCols();
    /* Send The Row */
        STP_voidSendSyncronous(Copy_u8Data[2],STP_SINGLE_BYTE_MODE);
        /* Send The Coulmn & Row */
    STP_voidSendSyncronous(0b11111011,STP_ALL_DATA_MODE);
    STP_voidSendSyncronous(Copy_u8Data[2],STP_ALL_DATA_MODE);
	STK_voidSetBusyWait(1300);

	DisableAllCols();
	/* Send The Row */
	    STP_voidSendSyncronous(Copy_u8Data[3],STP_SINGLE_BYTE_MODE);
	    /* Send The Coulmn & Row */
	STP_voidSendSyncronous(0b11110111,STP_ALL_DATA_MODE);
    STP_voidSendSyncronous(Copy_u8Data[3],STP_ALL_DATA_MODE);
	STK_voidSetBusyWait(1300);


	DisableAllCols();
	/* Send The Row */
	    STP_voidSendSyncronous(Copy_u8Data[4],STP_SINGLE_BYTE_MODE);
	    /* Send The Coulmn & Row */
	STP_voidSendSyncronous(0b11101111,STP_ALL_DATA_MODE);
	STP_voidSendSyncronous(Copy_u8Data[4],STP_ALL_DATA_MODE);
    STK_voidSetBusyWait(1300);

    DisableAllCols();
    /* Send The Row */
        STP_voidSendSyncronous(Copy_u8Data[5],STP_SINGLE_BYTE_MODE);
        /* Send The Coulmn & Row */
    STP_voidSendSyncronous(0b11011111,STP_ALL_DATA_MODE);
    STP_voidSendSyncronous(Copy_u8Data[5],STP_ALL_DATA_MODE);
	STK_voidSetBusyWait(1300);
	
	DisableAllCols();
	/* Send The Row */
	    STP_voidSendSyncronous(Copy_u8Data[6],STP_SINGLE_BYTE_MODE);
	    /* Send The Coulmn & Row */
	STP_voidSendSyncronous(0b10111111,STP_ALL_DATA_MODE);
    STP_voidSendSyncronous(Copy_u8Data[6],STP_ALL_DATA_MODE);
	STK_voidSetBusyWait(1300);

	DisableAllCols();
	/* Send The Row */
	    STP_voidSendSyncronous(Copy_u8Data[7],STP_SINGLE_BYTE_MODE);
	    STP_voidSetShiftRegister();
	    /* Send The Coulmn & Row */
	STP_voidSendSyncronous(0b01111111,STP_ALL_DATA_MODE);
	STP_voidSendSyncronous(Copy_u8Data[7],STP_ALL_DATA_MODE);
    STK_voidSetBusyWait(1300);

}

}
void LEDMRX_voidDisplayFrame(u8 *Copy_u8FrameData,u8 Copy_u8FrameSize)
{      u8 Local_Temp[8];
	   u8 Local_startindex = 0;
	   while(Local_startindex <= (Copy_u8FrameSize-7))
	   {
	   for(u8 i=0;i <= 7;i++){

		   Local_Temp[i] = Copy_u8FrameData[Local_startindex];

		   Local_startindex++;
		   if(i == 8){
			   Local_startindex--;
		   }
	   }
	   Local_startindex -= 6;

	   LEDMRX_voidDisplay(Local_Temp);

       }
}
