/*
 * main.c
 *
 *  Created on: Oct 13, 2020
 *      Author: Ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "UART_interface.h"
#include "FPEC_interface.h"

#include "ESP_interface.h"

void Parser_voidParseRecord(u8* Copy_u8BufData);

volatile u8*  u8RecBuffer   ;
volatile u8  u8RecCounter    = 0;
volatile u8  u8TimeOutFlag   = 0;
volatile u16 u16TimerCounter = 0;
volatile u8  u8BLWriteReq    = 1;
typedef void (*Function_t)(void);
Function_t addr_to_call = 0;

void func(void)
{
#define SCB_VTOR   *((volatile u32*)0xE000ED08)

	SCB_VTOR = 0x08002000;

	addr_to_call = *(Function_t*)(0x08002004);// addr_to_call = (Function_t)(0x08001004);
	addr_to_call();
}


void main(void)
{
	u8 Local_u8RecStatus;

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,14); /* USART1 */
	RCC_voidEnableClock(RCC_APB2,2);  /* PortA  */
	RCC_voidEnableClock(RCC_AHB,4);   /* FPEC   */


	GPIO_voidSetPinDirection(PORTA,9,0b1010);   /* TX AFPP */
	GPIO_voidSetPinDirection(PORTA,10,0b0100);  /* RX Input Floating */

	UART1_voidInit();
	ESP_voidInit();
	ESP_voidWifiConnect();

	u8 x=0;
	while(1)
	{
		/*********send ok*****************/
		ESP_voidServerConnect();
		ESP_voidSendOkToServer();


		if (u8BLWriteReq == 1)
		{
			FPEC_voidEraseAppArea();
			u8BLWriteReq = 0;
		}

		// Parse *
		ESP_voidServerConnect();
		u8RecBuffer= ESP_voidGetRecordFromServer();
		for(x=0;x<10;++x)
		{
			Parser_voidParseRecord(&u8RecBuffer[x*100]);
		}

	}


	/*while(u8TimeOutFlag == 0)
	{

		Local_u8RecStatus = UART1_u8ReceiveSynch(100);
		if (Local_u8RecStatus == 1)
		{
			STK_voidStopInterval();

			if(u8RecBuffer[u8RecCounter] == '\n' && u8RecBuffer[0] == ':')
			{
				if (u8BLWriteReq == 1)
				{
					FPEC_voidEraseAppArea();
					u8BLWriteReq = 0;
				}

				// Parse *
				Parser_voidParseRecord(u8RecBuffer);
				UART1_voidTransmitSynch("ok");
				u8RecCounter = 0;
			}

			else
			{
				u8RecCounter ++ ;
			}

			STK_voidSetIntervalSingle(15000000,func);
		}

		else
		{

		}
	}*/
}
