/***************************************/
/* Author  :Gomaa                      */
/* Date    :7 Seb 2020                 */
/* Version :V01                        */
/***************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "RCC_interface.h"
#include  "STK_interface.h"
#include  "GPIO_interface.h"
#include  "GPIO_private.h"

#include  "DAC_interface.h"
#include  "DAC_private.h"
#include  "DAC_config.h"

/* DAC Initialization */
void DAC_voidDacInit(void)
{  /* Clock Enable Of Ports */
#if   DAC_PORT == DAC_PORTA
    RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
#elif DAC_PORT == DAC_PORTB
    RCC_voidEnableClock(RCC_APB2,RCC_IOPB);
#elif DAC_PORT == DAC_PORTC
RCC_voidEnableClock(RCC_APB2,RCC_IOPC);
#endif
    /* SysTick Init */
     STK_voidInit();	
	/* HalfPort Configrations */
	GPIO_voidSetHalfPortDirection(DAC_HALF_PORT, GPIO_OUTPUTHP_2MHZ_PP);
	
}
void DAC_voidSetDAC(u8 *Copy_u8Samples,u32 Copy_u32NumOfSamples,u16 Copy_u16TicksOfConversion)
{  /* Set Refrence of Samples Array */
	Samples = Copy_u8Samples;
	/* Set Number  of Samples in Samples Array */
	NumOfSamples = Copy_u32NumOfSamples;
	/* Set Number  of Ticks Between Samples  */
	TicksOfConversion = Copy_u16TicksOfConversion;
	
}
static void SetDac(void)
{
	/* Set The Current Sample Value on HalfPort  */
	GPIO_voidSetHalfPortValue(DAC_HALF_PORT,Samples[counter]);
	counter++;
	if(counter == NumOfSamples)
	{
		counter = 0;
	}
    
	
	
	
}
void DAC_voidStartDAC(void)
{
	/* Start The Conversion */
	STK_voidSetIntervalPeriodic(TicksOfConversion,SetDac);
}	


