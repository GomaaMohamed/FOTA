/***************************************/
/* Author  :Gomaa                      */
/* Date    :28 Seb 2020                 */
/* Version :V01                        */
/***************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "USART_interface.h"



#include  "ESP_interface.h"
#include  "ESP_private.h"
#include  "ESP_config.h"

void ESP_voidInit(void)
{ 
u8 Locale_Result =0 
while(Locale_Result == 0){
/* stop ECHO */
	USART_voidTransmit("ATE0\r\n");
	Locale_Result = EspValidateCmd();
}
while(Locale_Result == 0){
/* Set Station Mode */
	USART_voidTransmit("AT+CWMODE=1\r\n");
	Locale_Result = EspValidateCmd();
}
	
	
}

u8 EspValidateCmd(void)
{
	u8 Locale_Response[100] = {0};
	u8 i = 0;
	u8 Dummy = 0;
	u8 Result = 0;
	while(Dummy != 255)
	{
		Dummy = USART_u8Receive();
		Locale_Response[i] = Dummy;
		i++;
		
	}
 if(Locale_Response[0] == 'o' && Locale_Response[1] == 'k')
 {
	Result = 1;
 }
  return Result;
	
 }