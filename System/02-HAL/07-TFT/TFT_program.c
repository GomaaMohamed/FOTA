/***************************************/
/* Author  :Gomaa                      */
/* Date    :21 Seb 2020                 */
/* Version :V01                        */
/***************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "STK_interface.h"
#include  "GPIO_interface.h"
#include  "SPI_interface.h"


#include  "TFT_interface.h"
#include  "TFT_private.h"
#include  "TFT_config.h"


void TFT_voidInit(void)
{
	/* Reset Pulse */
	GPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	STK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN,GPIO_LOW);
	STK_voidSetBusyWait(1);
	GPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	STK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN,GPIO_LOW);
	STK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	STK_voidSetBusyWait(120000);
	
	/* sleep out cmnd */
	WriteCommand(0x11);
	STK_voidSetBusyWait(150000);
	
	/* Color Mode Command */
	WriteCommand(0x3A);
	WriteData(0x05);
	
	/* Display On Command */
	WriteCommand(0x29);
	
	
	
	
	

}
void  TFT_voidFillBackGround(u16 Copy_u16Color)
{  CallColor = Copy_u16Color;
	volatile u16 counter;
	volatile u8 Data;
	/* Set X Address */
	WriteCommand(0x2A);
	WriteData(0);
	WriteData(0);
    WriteData(0);
    WriteData(127);
    /* Set Y Address */
    	WriteCommand(0x2B);
    	WriteData(0);
    	WriteData(0);
        WriteData(0);
        WriteData(159);
   /* Write The Pixels */
        WriteCommand(0x2C);
        for(counter = 0;counter < 20480; counter++)
        {
        	Data = Copy_u16Color >> 8;
        	 WriteData(Data);
        	 Data = Copy_u16Color & 0x00FF;
        	 WriteData(Data);

        }





}
void  TFT_voidDisplayImage(const u16* Copy_Image)
{
	volatile u16 counter;
	volatile u8 Data;
	/* Set X Address */
	WriteCommand(0x2A);
	WriteData(0);
	WriteData(0);
    WriteData(0);
    WriteData(127);
    /* Set Y Address */
    	WriteCommand(0x2B);
    	WriteData(0);
    	WriteData(0);
        WriteData(0);
        WriteData(159);
   /* Write The Pixels */
        WriteCommand(0x2C);
        for(counter = 0;counter < 20480; counter++)
        {
        	Data = Copy_Image[counter] >> 8;
        	 WriteData(Data);
        	 Data = Copy_Image[counter] & 0x00FF;
        	 WriteData(Data);

        }



	
	
}
void  TFT_voidDrawRectangle(u8 x1,u8 x2,u8 y1,u8 y2,u16 Copy_u16Color)
{


	u16 counter;
	u16 size =(x2-x1+1)*(y2-y1+1);
	u8 Data;
	if((x2>=x1)&&(y2>=y1))    // Data Validation
	{
		/*  Set X Address  */
							WriteCommand(0x2A);
							/*    Start        */
							WriteData(0);
							WriteData(x1);
							/*    End        */
							WriteData(0);
							WriteData(x2);

							/*  Set Y Address  */
							WriteCommand(0x2B);
							/*    Start        */
							WriteData(0);
							WriteData(y1);
							/*    End        */
							WriteData(0);
							WriteData(y2);




		/*  RAM  Write    */
		WriteCommand(0x2C);
		for(counter =0;counter<size;counter++)
		{

			Data =Copy_u16Color>>8;
			/* Write the high byte */
			WriteData(Data);
			/* Write the low byte */
			Data =Copy_u16Color & 0x00ff;
			WriteData(Data);
		}
	}
}
void  TFT_voidWriteChar(u8 x1, u8 y1,u16 Copy_u16Color, u8 Copy_u8Char)
{    TFT_voidDeleteCharNum(x1,y1);
     switch(Copy_u8Char){
     case 'D':
	    TFT_voidDrawRectangle(x1+8,x1+9,y1,y1+11,Copy_u16Color);
	    TFT_voidDrawRectangle(x1+2,x1+7,y1,y1+1,Copy_u16Color);
	    TFT_voidDrawRectangle(x1+2,x1+7,y1+10,y1+11,Copy_u16Color);
	    TFT_voidDrawRectangle(x1,x1+1,y1+2,y1+9,Copy_u16Color);
	 break;
     case 'A':
     	TFT_voidDrawRectangle(x1,x1+1,y1,y1+8,Copy_u16Color);
     	TFT_voidDrawRectangle(x1+8,x1+9,y1,y1+8,Copy_u16Color);
     	TFT_voidDrawRectangle(x1+2,x1+7,y1+5,y1+6,Copy_u16Color);
     	TFT_voidDrawRectangle(x1+3,x1+6,y1+10,y1+11,Copy_u16Color);
     	TFT_voidDrawRectangle(x1+1,x1+2,y1+8,y1+9,Copy_u16Color);
     	TFT_voidDrawRectangle(x1+2,x1+3,y1+9,y1+10,Copy_u16Color);
     	TFT_voidDrawRectangle(x1+7,x1+8,y1+8,y1+9,Copy_u16Color);
     	TFT_voidDrawRectangle(x1+6,x1+7,y1+9,y1+10,Copy_u16Color);
     break;
     case 'T':
     	    TFT_voidDrawRectangle(x1,x1+9,y1+10,y1+11,Copy_u16Color);
     	    TFT_voidDrawRectangle(x1+4,x1+5,y1,y1+9,Copy_u16Color);

     break;
     case 'E':
          	TFT_voidDrawRectangle(x1+8,x1+9,y1,y1+11,Copy_u16Color);
          	TFT_voidDrawRectangle(x1,x1+7,y1,y1+1,Copy_u16Color);
          	TFT_voidDrawRectangle(x1,x1+7,y1+10,y1+11,Copy_u16Color);
          	TFT_voidDrawRectangle(x1+2,x1+7,y1+5,y1+6,Copy_u16Color);
          	TFT_voidDrawRectangle(x1,x1+1,y1+4,y1+7,Copy_u16Color);

     break;
     case 'I':
    	 TFT_voidDrawRectangle(x1+2,x1+7,y1,y1+1,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+2,x1+7,y1+10,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+4,x1+5,y1+2,y1+9,Copy_u16Color);
     break;
     case 'S':
    	 TFT_voidDrawRectangle(x1,x1+9,y1,y1+1,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+9,y1+5,y1+6,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+9,y1+10,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+1,y1+2,y1+4,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+8,x1+9,y1+7,y1+9,Copy_u16Color);
     break;
     case 'P':
    	 TFT_voidDrawRectangle(x1+8,x1+9,y1,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+7,y1+5,y1+6,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+7,y1+10,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+1,y1+7,y1+9,Copy_u16Color);
     break;
     case 'M':
    	 TFT_voidDrawRectangle(x1,x1+1,y1,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+8,x1+9,y1,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+3,x1+6,y1+8,y1+9,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+4,x1+5,y1+7,y1+7,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+2,x1+3,y1+9,y1+10,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+6,x1+7,y1+9,y1+10,Copy_u16Color);
    	 break;
     case 'H':
         	 TFT_voidDrawRectangle(x1,x1+1,y1,y1+11,Copy_u16Color);
         	 TFT_voidDrawRectangle(x1+8,x1+9,y1,y1+11,Copy_u16Color);
         	 TFT_voidDrawRectangle(x1+2,x1+7,y1+5,y1+6,Copy_u16Color);

         	 break;
     case '-':
    	 TFT_voidDrawRectangle(x1+3,x1+6,y1+5,y1+6,Copy_u16Color);
     break;
     case ':':
    	 TFT_voidDrawRectangle(x1+4,x1+5,y1+2,y1+3,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+4,x1+5,y1+6,y1+7,Copy_u16Color);







     }
}
void  TFT_voidWriteNum(u8 x1, u8 y1,u16 Copy_u16Color, u8 Copy_u8Number)
{    TFT_voidDeleteCharNum(x1,y1);
     switch(Copy_u8Number){
     case 0:
	    TFT_voidDrawRectangle(x1,x1+1,y1,y1+11,Copy_u16Color);
	    TFT_voidDrawRectangle(x1+8,x1+9,y1,y1+11,Copy_u16Color);
	    TFT_voidDrawRectangle(x1+2,x1+7,y1,y1+1,Copy_u16Color);
	    TFT_voidDrawRectangle(x1+2,x1+7,y1+10,y1+11,Copy_u16Color);
	 break;
     case 1:
     	TFT_voidDrawRectangle(x1+2,x1+7,y1,y1+1,Copy_u16Color);
     	TFT_voidDrawRectangle(x1+4,x1+5,y1+2,y1+11,Copy_u16Color);
     	TFT_voidDrawRectangle(x1+6,x1+6,y1+9,y1+11,Copy_u16Color);
     break;
     case 2:
     	    TFT_voidDrawRectangle(x1,x1+9,y1,y1+1,Copy_u16Color);
     	    TFT_voidDrawRectangle(x1,x1+9,y1+4,y1+5,Copy_u16Color);
     	    TFT_voidDrawRectangle(x1,x1+9,y1+10,y1+11,Copy_u16Color);
     	    TFT_voidDrawRectangle(x1,x1+1,y1+6,y1+9,Copy_u16Color);
     	    TFT_voidDrawRectangle(x1+8,x1+9,y1+2,y1+3,Copy_u16Color);
     	    TFT_voidDrawRectangle(x1+8,x1+9,y1+9,y1+9,Copy_u16Color);

     break;
     case 3:
          	TFT_voidDrawRectangle(x1,x1+1,y1,y1+11,Copy_u16Color);
          	TFT_voidDrawRectangle(x1,x1+9,y1,y1+1,Copy_u16Color);
          	TFT_voidDrawRectangle(x1,x1+9,y1+10,y1+11,Copy_u16Color);
          	TFT_voidDrawRectangle(x1,x1+7,y1+5,y1+6,Copy_u16Color);

     break;
     case 4:
    	 TFT_voidDrawRectangle(x1,x1+1,y1,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+8,x1+9,y1+5,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+2,x1+7,y1+5,y1+6,Copy_u16Color);
     break;
     case 5:
    	 TFT_voidDrawRectangle(x1,x1+9,y1,y1+1,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+9,y1+10,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+9,y1+6,y1+7,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+1,y1+2,y1+5,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+8,x1+9,y1+8,y1+9,Copy_u16Color);
     break;
     case 6:
    	 TFT_voidDrawRectangle(x1,x1+9,y1,y1+1,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+9,y1+10,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+9,y1+5,y1+6,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+1,y1+2,y1+4,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+8,x1+9,y1+2,y1+4,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+8,x1+9,y1+7,y1+9,Copy_u16Color);
     break;
     case 7:
    	 TFT_voidDrawRectangle(x1,x1+1,y1,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+2,x1+3,y1+5,y1+6,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+7,y1+10,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+6,x1+7,y1+9,y1+9,Copy_u16Color);

    	 break;
     case 8:
    	 TFT_voidDrawRectangle(x1,x1+9,y1,y1+1,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+9,y1+10,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+9,y1+5,y1+6,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+1,y1+2,y1+4,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+8,x1+9,y1+2,y1+4,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1+8,x1+9,y1+7,y1+9,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+1,y1+7,y1+9,Copy_u16Color);
     break;
     case 9:
    	 TFT_voidDrawRectangle(x1,x1+9,y1,y1+1,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+9,y1+10,y1+11,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+9,y1+5,y1+6,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+1,y1+2,y1+4,Copy_u16Color);

    	 TFT_voidDrawRectangle(x1+8,x1+9,y1+7,y1+9,Copy_u16Color);
    	 TFT_voidDrawRectangle(x1,x1+1,y1+7,y1+9,Copy_u16Color);







     }
}

void  TFT_voidDeleteCharNum(u8 x1, u8 y1)
{
	volatile u16 counter;
		volatile u8 Data;
		/* Set X Address */
		WriteCommand(0x2A);
		WriteData(0);
		WriteData(x1);
	    WriteData(0);
	    WriteData(x1+9);
	    /* Set Y Address */
	    	WriteCommand(0x2B);
	    	WriteData(0);
	    	WriteData(y1);
	        WriteData(0);
	        WriteData(y1+11);
	   /* Write The Pixels */
	        WriteCommand(0x2C);
	        for(counter = 0;counter < 100; counter++)
	        {
	        	Data = CallColor >> 8;
	        	 WriteData(Data);
	        	 Data = CallColor & 0x00FF;
	        	 WriteData(Data);

	        }


}

static void WriteCommand(u8 Copy_u8Command)
{
	u8 Locale_Temp;
	/* Set A0 Pin To low */
	GPIO_voidSetPinValue(TFT_A0_PIN,GPIO_LOW);
	
	/* Send Command over spi */
	SPI_voidSendReceiveSynch(Copy_u8Command,&Locale_Temp);
	
}
static void WriteData(u8 Copy_u8Data)
{
	u8 Locale_Temp;
	/* Set A0 Pin To high */
	GPIO_voidSetPinValue(TFT_A0_PIN,GPIO_HIGH);
	
	/* Send Data over spi */
	SPI_voidSendReceiveSynch(Copy_u8Data,&Locale_Temp);
}
