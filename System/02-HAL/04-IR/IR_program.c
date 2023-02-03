/***************************************/
/* Author  :Gomaa                      */
/* Date    :2  Seb 2020                 */
/* Version :V01                        */
/***************************************/

#include   "STD_TYPES.h"
#include   "BIT_MATH.h"

#include    "AFIO_interface.h"
#include     "GPIO_interface.h"
#include     "STK_interface.h"
#include     "NVIC_interface.h"
#include     "EXTI_interface.h"
#include     "RCC_interface.h"


#include      "IR_interface.h"
#include      "IR_private.h"
#include      "IR_config.h"


void IR_voidIRInit(void)
{  /* Enable AFIO Clock */
	RCC_voidEnableClock(RCC_APB2,RCC_AFIO);
	/* Initialization of SysTick */
    STK_voidInit();
	
#if     IR_LINE ==  IR_LINE0  &&	  IR_PORT ==  IR_PORTA
    /* Set CallBack of EXTI0 */
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    /* Enable  Clock Of PORTA */
    RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
	/* Initialization of A0 */
	GPIO_voidSetPinDirection(GPIOA,GPIO_PIN0,GPIO_INPUT_FLOATING);
	/* Select A0 to be EXTI */
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE0 ,AFIO_EXTI_PORTA);
	/* Select Line0 to be EXTI */
	EXTI_voidEnableExti(EXTI_LINE0 ,EXTI_FALLING);
	/* Enable EXTI0 to Interrupt */
	NVIC_voidEnableInterrupt(6);
#elif     IR_LINE ==  LINE0  &&	  IR_PORT ==  IR_PORTB
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPB);
	GPIO_voidSetPinDirection(GPIOB,GPIO_PIN0,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE0,AFIO_EXTI_PORTB);
	EXTI_voidEnableExti(EXTI_LINE0,EXTI_FALLING);
	NVIC_voidEnableInterrupt(6);
#elif     IR_LINE ==  IR_LINE0  &&	  IR_PORT ==  IR_PORTC
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPC);
	GPIO_voidSetPinDirection(GPIOC,GPIO_PIN0,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE0,AFIO_EXTI_PORTC);
	EXTI_voidEnableExti(EXTI_LINE0,EXTI_FALLING);
	NVIC_voidEnableInterrupt(6);
	
	
#elif     IR_LINE ==  IR_LINE1  &&	  IR_PORT ==  IR_PORTA
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
	GPIO_voidSetPinDirection(GPIOA,GPIO_PIN1,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE1,AFIO_EXTI_PORTA);
	EXTI_voidEnableExti(EXTI_LINE1,EXTI_FALLING);
	NVIC_voidEnableInterrupt(7);
#elif     IR_LINE ==  LINE1 &&	  IR_PORT ==  IR_PORTB
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPB);
	GPIO_voidSetPinDirection(GPIOB,GPIO_PIN1,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE1,AFIO_EXTI_PORTB);
	EXTI_voidEnableExti(EXTI_LINE1,EXTI_FALLING);
	NVIC_voidEnableInterrupt(7);
#elif     IR_LINE ==  IR_LINE1  &&	  IR_PORT ==  IR_PORTC
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPC);
	GPIO_voidSetPinDirection(GPIOC,GPIO_PIN1,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE1,AFIO_EXTI_PORTC);
	EXTI_voidEnableExti(EXTI_LINE1,EXTI_FALLING);
	NVIC_voidEnableInterrupt(7);	
	
#elif     IR_LINE ==  IR_LINE2  &&	  IR_PORT ==  IR_PORTA
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
	GPIO_voidSetPinDirection(GPIOA,GPIO_PIN2,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE2,AFIO_EXTI_PORTA);
	EXTI_voidEnableExti(EXTI_LINE2,EXTI_FALLING);
	NVIC_voidEnableInterrupt(8);
#elif     IR_LINE ==  LINE2  &&	  IR_PORT ==  IR_PORTB
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPB);
	GPIO_voidSetPinDirection(GPIOB,GPIO_PIN2,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE2,AFIO_EXTI_PORTB);
	EXTI_voidEnableExti(EXTI_LINE2,EXTI_FALLING);
	NVIC_voidEnableInterrupt(8);
#elif     IR_LINE ==  IR_LINE2  &&	  IR_PORT ==  IR_PORTC
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPC);
	GPIO_voidSetPinDirection(GPIOC,GPIO_PIN2,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE2,AFIO_EXTI_PORTC);
	EXTI_voidEnableExti(EXTI_LINE2,EXTI_FALLING);
	NVIC_voidEnableInterrupt(8);	
	
#elif     IR_LINE ==  IR_LINE3  &&	  IR_PORT ==  IR_PORTA
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
	GPIO_voidSetPinDirection(GPIOA,GPIO_PIN3,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE3,AFIO_EXTI_PORTA);
	EXTI_voidEnableExti(EXTI_LINE3,EXTI_FALLING);
	NVIC_voidEnableInterrupt(9);
#elif     IR_LINE ==  LINE3  &&	  IR_PORT ==  IR_PORTB
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPB);
	GPIO_voidSetPinDirection(GPIOB,GPIO_PIN0,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE3,AFIO_EXTI_PORTB);
	EXTI_voidEnableExti(EXTI_LINE3,EXTI_FALLING);
	NVIC_voidEnableInterrupt(9);
#elif     IR_LINE ==  IR_LINE3  &&	  IR_PORT ==  IR_PORTC
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPC);
	GPIO_voidSetPinDirection(GPIOC,GPIO_PIN3,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE3,AFIO_EXTI_PORTC);
	EXTI_voidEnableExti(EXTI_LINE3,EXTI_FALLING);
	NVIC_voidEnableInterrupt(9);
	
#elif     IR_LINE ==  IR_LINE4  &&	  IR_PORT ==  IR_PORTA
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
	GPIO_voidSetPinDirection(GPIOA,GPIO_PIN4,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE4,AFIO_EXTI_PORTA);
	EXTI_voidEnableExti(EXTI_LINE4,EXTI_FALLING);
	NVIC_voidEnableInterrupt(10);
#elif     IR_LINE ==  LINE4  &&	  IR_PORT ==  IR_PORTB
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPB);
	GPIO_voidSetPinDirection(GPIOB,GPIO_PIN4,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE4,AFIO_EXTI_PORTB);
	EXTI_voidEnableExti(EXTI_LINE4,EXTI_FALLING);
	NVIC_voidEnableInterrupt(10);
#elif     IR_LINE ==  IR_LINE4  &&	  IR_PORT ==  IR_PORTC
	EXTI_voidSetCallback(GetFrame,IR_LINE);
    RCC_voidEnableClock(RCC_APB2,RCC_IOPC);
	GPIO_voidSetPinDirection(GPIOC,GPIO_PIN4,GPIO_INPUT_FLOATING);
	AFIO_voidSetExtiConfig(AFIO_EXTI_LINE4,AFIO_EXTI_PORTC);
	EXTI_voidEnableExti(EXTI_LINE4,EXTI_FALLING);
	NVIC_voidEnableInterrupt(10);	
#endif	
}
u8   IR_u8ReturnActiveButton(void)
{
	return Temp;
	
}
static void TakeAction(void)
{
	Data = 0;
	if((FramData[0] >= 10000) && (FramData[0] <= 14000))
	{
     	for(u8 i = 0;i <= 7; i++)
       	{
		   if((FramData[17+i] >= 2000) && (FramData[17+i] <= 2300))
		   {
                SET_BIT(Data,i);
		   }
		   else
		   {

			CLR_BIT(Data,i);
		   }

	    }
	}
	else
	{


	}
	Temp = Data;
	         FramData[0] = 0;
			 flag = 0;
		     edgecounter = 0;

}
static void GetFrame(void){

	if(flag == 0){

		STK_voidSetIntervalSingle(200000,TakeAction);
		flag = 1;
	}
	else{
   FramData[edgecounter] = STK_u32GetElapsedTime();
   STK_voidSetIntervalSingle(200000,TakeAction);
   edgecounter++;
	}

}

