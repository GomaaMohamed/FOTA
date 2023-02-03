/************************************************/
/* Author :Hussin Ebrahim                       */
/* Date   :30/9/2020                            */
/* Version:V01                                  */
/************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"UART_interface.h"

#include"ESP_interface.h"
#include"ESP_private.h"
#include"ESP_config.h"

u8 Global_u8StatusVal=255;

u8 Global_u8Response[1000] ;
void ESP_voidInit(void)
{
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		// Stop ECHO
		UART1_voidTransmitSynch("ATE0\r\n");
		Local_u8Result = voidEspValidateCmd(ESP_INIT_TIMEOUT);
	}
	
	Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Set station mode */
		UART1_voidTransmitSynch("AT+CWMODE=1\r\n");
		Local_u8Result = voidEspValidateCmd(ESP_INIT_TIMEOUT);
	}
}

//AT+CWJAP_CUR="Apple","1998_2021_balah" 
void ESP_voidWifiConnect(void)
{
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Wifi connect */
		UART1_voidTransmitSynch(SSID_PASS);
		Local_u8Result = voidEspValidateCmd(ESP_WIFI_TIMEOUT);
	}
	
}

void ESP_voidServerConnect(void)
{
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Server connect */
		UART1_voidTransmitSynch(SERVER_IP);
		Local_u8Result = voidEspValidateCmd(ESP_SERVER_CONNECT_TIMEOUT);
	}
	
}


/*AT+CIPSEND=42

GET http://Hussin.freevar.com/status.txt */

u8 ESP_voidGetValFromServer(void)
{
	u8 Local_u8Result = 0;

	while(Local_u8Result == 0)
	{
		/* No of Character of Status file Address */
		UART1_voidTransmitSynch("AT+CIPSEND=46\r\n");
		Local_u8Result = voidEspValidateCmd(ESP_GET_SERVER_VAL_TIMEOUT);
	}

	Local_u8Result = 0;

	//while(Local_u8Result == 0)
	//{
		/* get value from Status.txt */
		UART1_voidTransmitSynch("GET http://Hussin2020.freevar.com/status.txt\r\n");
		Local_u8Result = voidEspValidateCmd(300000);
	//}
	return Global_u8StatusVal;

}

/**********************************************************/
void ESP_voidSendOkToServer(void)
{

	u8 Local_u8Result = 0;
	u8 i=8;

	while(Local_u8Result == 0)
	{
		/* No of Character of Status file Address */
		UART1_voidTransmitSynch("AT+CIPSEND=53\r\n");
		Local_u8Result = voidEspValidateCmd(50000);
	}

	Local_u8Result = 0;

	//while(Local_u8Result == 0)
	//{
		/* get value from Status.txt */
		UART1_voidTransmitSynch("GET http://hussin2020.freevar.com/Reciver.php?Rx=ok\r\n");
		Local_u8Result = voidEspValidateCmd(100000);
	//}

}




/**********************************************************/
 u8* ESP_voidGetRecordFromServer(void)
{

	static volatile u8 Local_u8Response[10][100]={0};
	volatile u8 Local_u8Result = 0;
	volatile u16 i=8;
	volatile u16 x=0,y=0;

	while(Local_u8Result == 0)
	{
		/* No of Character of Status file Address */
		UART1_voidTransmitSynch("AT+CIPSEND=46\r\n");
		Local_u8Result = voidEspValidateCmd(ESP_GET_SERVER_VAL_TIMEOUT);
	}

	Local_u8Result = 0;

	//while(Local_u8Result == 0)
	//{
		/* get value from Status.txt */
		UART1_voidTransmitSynch("GET http://Hussin2020.freevar.com/Record.txt\r\n");
		Local_u8Result = voidEspValidateCmd(250000);
	//}
	while(Global_u8Response[i]!=':')
	{
		++i;
	}

	for(y=0;y<10;)
	{
		x=0;
		do
		{
			Local_u8Response[y][x++]=Global_u8Response[++i];

		}while(Global_u8Response[i]!='\r');

		++y;
		++i;
	}


	return  Local_u8Response ;

}

u8 voidEspValidateCmd(u32 Copy_u32TimeOut)
{

	u16 i = 0;
	u8 Dummy = 0;
	u8 Result = 0;
	
	while (Dummy != 255)
	{
		Dummy = UART1_u8ReceiveSynch(Copy_u32TimeOut);
		Global_u8Response[i] = Dummy;
		i++;
	}
	
	/* Check if Ok */
	if (Global_u8Response[i-5] == 'O' && Global_u8Response[i-4] == 'K')
	{
		Result = 1;
	}
	
	else if (Global_u8Response[i-7] == 'O' && Global_u8Response[i-6] == 'K'&& Global_u8Response[i-3] == '>')
	{
		Result = 1;
	}
	else if  (Global_u8Response[i-17] == '+' && Global_u8Response[i-13] == ','&& Global_u8Response[i-11] == ':')
	{
		Result = 1;
		Global_u8StatusVal=Global_u8Response[i-10];
	}

	return Result;
}
