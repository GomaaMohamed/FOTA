/*******************************************/
/* Author:Hussin Ebrahim                   */
/* Date  :20/9/2020                        */
/* Versin:V01                              */
/*******************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"UART_interface.h"
#include"UART_private.h"
#include"UART_config.h"


void UART1_voidInit(void)
{
	/*   Baud Rate  =115200      */
	UART1->BRR= UARTx_BAUD_RATE ;
	
	/*    Word Length          */
	#if   UART_WORD_LENGHT==UART_1_START_BIT_8_DATA_BITS
		CLR_BIT(UART1->CR1,UARTx_CR1_M);
	#elif UART_WORD_LENGHT==UART_1_START_BIT_9_DATA_BITS
		SET_BIT(UART1->CR1,UARTx_CR1_M);
	#endif
	
	/* Parity Control          */
	#if   UART_PARITY_CONTROL==UART_PARITY_DISABLE
		CLR_BIT(UART1->CR1,UARTx_CR1_PCE);
		
	#elif UART_PARITY_CONTROL==UART_PARITY_ENABLE
		SET_BIT(UART1->CR1,UARTx_CR1_PCE);
		
		#if   UART_PARITY_SELECTION==UART_EVEN_PARITY
			CLR_BIT(UART1->CR1,UARTx_CR1_PS);
			
		#elif UART_PARITY_SELECTION==UART_ODD_PARITY	
			SET_BIT(UART1->CR1,UARTx_CR1_PS);
			
		#endif	
	
	#endif
	

	/*   No of Stop Bits       */
	UART1->CR2 &=~(0b11            <<UARTx_CR2_STOP);
	UART1->CR2 |= (UARTx_1_STOP_BIT<<UARTx_CR2_STOP);
		
	/*   Receive Enable        */
	SET_BIT(UART1->CR1,UARTx_CR1_RE);
	/*   Transmission Enable   */
	SET_BIT(UART1->CR1,UARTx_CR1_TE);
	/*   UART Enable           */
	SET_BIT(UART1->CR1,UARTx_CR1_UE);
	
	/* Clear Status Register*/
	UART1->SR=0;
}
void UART1_voidTransmitSynch(u8 Arr[])
{
	u8 i=0;

	while(Arr[i] !='\0')
	{
		UART1->DR=Arr[i];
		/* Wait till Transmission is complete */
		while(GET_BIT(UART1->SR,6)==0);
		++i;
	}
}

void UART1_voidTransmitASynch(u8 Arr[])
{

	Global_pu8ArryUART1=Arr;
	if(Arr[0] !='\0')
	{
		SET_BIT(UART1->CR1,UARTx_CR1_TCIE);/* Enable interrupt */
		UART1->DR=Arr[0];
	}
}

u8   UART1_u8ReceiveSynch(u32 Copy_u32Timeout)
{
	u32 timeout=0;
	u8 Loc_u8ReceiveData=0;
	/*  Wait Till Received data is ready to read*/
	while(GET_BIT(UART1->SR,5)==0)
	{
		timeout++;
		if(timeout==Copy_u32Timeout)
		{
			Loc_u8ReceiveData=255;
			break;
		}
	}
	if(Loc_u8ReceiveData==0)
	{
		Loc_u8ReceiveData=UART1->DR;
	}
	return (Loc_u8ReceiveData);
}

void UART1_voidReceiveASynch(void (* CallBack)(u8))
{
	UART1_CallBack=CallBack;
	SET_BIT(UART1->CR1,UARTx_CR1_RXNEIE);/* Enable interrupt */

}
/*******************************UART2***************************************/
void UART2_voidInit(void)
{
	/*   Baud Rate  =9600      */
	UART2->BRR= UARTx_BAUD_RATE ;

	/*    Word Length          */
	#if   UART_WORD_LENGHT==UART_1_START_BIT_8_DATA_BITS
		CLR_BIT(UART2->CR1,UARTx_CR1_M);
	#elif UART_WORD_LENGHT==UART_1_START_BIT_9_DATA_BITS
		SET_BIT(UART2->CR1,UARTx_CR1_M);
	#endif

	/* Parity Control          */
	#if   UART_PARITY_CONTROL==UART_PARITY_DISABLE
		CLR_BIT(UART2->CR1,UARTx_CR1_PCE);

	#elif UART_PARITY_CONTROL==UART_PARITY_ENABLE
		SET_BIT(UART2->CR1,UARTx_CR1_PCE);

		#if   UART_PARITY_SELECTION==UART_EVEN_PARITY
			CLR_BIT(UART2->CR1,UARTx_CR1_PS);

		#elif UART_PARITY_SELECTION==UART_ODD_PARITY
			SET_BIT(UART2->CR1,UARTx_CR1_PS);

		#endif

	#endif


	/*   No of Stop Bits       */
	UART2->CR2 &=~(0b11            <<UARTx_CR2_STOP);
	UART2->CR2 |= (UARTx_1_STOP_BIT<<UARTx_CR2_STOP);

	/*   Receive Enable        */
	SET_BIT(UART2->CR1,UARTx_CR1_RE);
	/*   Transmission Enable   */
	SET_BIT(UART2->CR1,UARTx_CR1_TE);
	/*   UART Enable           */
	SET_BIT(UART2->CR1,UARTx_CR1_UE);

	/* Clear Status Register*/
	UART2->SR=0;
}
void UART2_voidTransmitSynch(u8 Arr[])
{
	u8 i=0;
	while(Arr[i] !='\0')
	{
		UART2->DR=Arr[i];
		/* Wait till Transmission is complete */
		while(GET_BIT(UART2->SR,6)==0);
		++i;
	}
}

void UART2_voidTransmitASynch(u8 Arr[])
{

	Global_pu8ArryUART2=Arr;
	if(Arr[0] !='\0')
	{
		SET_BIT(UART2->CR1,UARTx_CR1_TCIE);/* Enable interrupt */
		UART2->DR=Arr[0];
	}
}

u8   UART2_u8ReceiveSynch(void)
{
	/*  Wait Till Received data is ready to read*/
	while(GET_BIT(UART2->SR,5)==0);
	return (0xFF &(UART2->DR));
}

void UART2_voidReceiveASynch(void (* CallBack)(u8))
{
	UART2_CallBack=CallBack;
	SET_BIT(UART2->CR1,UARTx_CR1_RXNEIE);/* Enable interrupt */

}

/*******************************UART3***************************************/
void UART3_voidInit(void)
{
	/*   Baud Rate  =9600      */
	UART3->BRR= UARTx_BAUD_RATE ;

	/*    Word Length          */
	#if   UART_WORD_LENGHT==UART_1_START_BIT_8_DATA_BITS
		CLR_BIT(UART3->CR1,UARTx_CR1_M);
	#elif UART_WORD_LENGHT==UART_1_START_BIT_9_DATA_BITS
		SET_BIT(UART3->CR1,UARTx_CR1_M);
	#endif

	/* Parity Control          */
	#if   UART_PARITY_CONTROL==UART_PARITY_DISABLE
		CLR_BIT(UART3->CR1,UARTx_CR1_PCE);

	#elif UART_PARITY_CONTROL==UART_PARITY_ENABLE
		SET_BIT(UART3->CR1,UARTx_CR1_PCE);

		#if   UART_PARITY_SELECTION==UART_EVEN_PARITY
			CLR_BIT(UART3->CR1,UARTx_CR1_PS);

		#elif UART_PARITY_SELECTION==UART_ODD_PARITY
			SET_BIT(UART3->CR1,UARTx_CR1_PS);

		#endif

	#endif


	/*   No of Stop Bits       */
	UART3->CR2 &=~(0b11            <<UARTx_CR2_STOP);
	UART3->CR2 |= (UARTx_1_STOP_BIT<<UARTx_CR2_STOP);

	/*   Receive Enable        */
	SET_BIT(UART3->CR1,UARTx_CR1_RE);
	/*   Transmission Enable   */
	SET_BIT(UART3->CR1,UARTx_CR1_TE);
	/*   UART Enable           */
	SET_BIT(UART3->CR1,UARTx_CR1_UE);

	/* Clear Status Register*/
	UART3->SR=0;
}
void UART3_voidTransmitSynch(u8 Arr[])
{
	u8 i=0;

	while(Arr[i] !='\0')
	{
		UART3->DR=Arr[i];
		/* Wait till Transmission is complete */
		while(GET_BIT(UART3->SR,UARTx_SR_TC)==0);
		++i;
	}
}

void UART3_voidTransmitASynch(u8 Arr[])
{

	Global_pu8ArryUART3=Arr;
	if(Arr[0] !='\0')
	{
		SET_BIT(UART3->CR1,UARTx_CR1_TCIE);/* Enable interrupt */
		UART3->DR=Arr[0];
	}
}

u8   UART3_u8ReceiveSynch(void)
{
	/*  Wait Till Received data is ready to read*/
	while(GET_BIT(UART3->SR,5)==0);
	return (0xFF &(UART3->DR));
}

void UART3_voidReceiveASynch(void (* CallBack)(u8))
{
	UART3_CallBack=CallBack;
	SET_BIT(UART3->CR1,UARTx_CR1_RXNEIE);/* Enable interrupt */

}
/********************************************************************/

void USART1_IRQHandler(void)
{
	if(GET_BIT(UART1->SR,UARTx_SR_TC)==1)
	{
		if(Global_pu8ArryUART1[UART1_COUNTER]!='\0')
		{
			UART1->DR=Global_pu8ArryUART1[UART1_COUNTER];
			++UART1_COUNTER;
			/* Transmission complete flag Cleared by
			 * Read UART3->SR
			 * Write toUART3->DR
			 */
		}
		else
		{
			CLR_BIT(UART1->CR1,UARTx_CR1_TCIE);/* Disable interrupt */
			UART1_COUNTER=1;
		}

		CLR_BIT(UART1->SR,UARTx_SR_TC);/* Clear Transmission complete flag*/

	}
	else if(GET_BIT(UART1->SR,UARTx_SR_RXNE)==1)
	{
		UART1_CallBack(UART1->DR);
		/* Read data Register not empty(RXNE)flag Cleard by
		 * by Read UART3->DR
		 * */

	}
}
/*************************************************************/
void USART2_IRQHandler(void)
{
	if(GET_BIT(UART2->SR,UARTx_SR_TC)==1)
	{
		if(Global_pu8ArryUART2[UART2_COUNTER]!='\0')
		{
			UART2->DR=Global_pu8ArryUART2[UART2_COUNTER];
			++UART2_COUNTER;
			/* Transmission complete flag Cleared by
			 * Read UART3->SR
			 * Write toUART3->DR
			 */
		}
		else
		{
			CLR_BIT(UART2->CR1,UARTx_CR1_TCIE);/* Disable interrupt */
			UART1_COUNTER=1;
		}

		CLR_BIT(UART2->SR,UARTx_SR_TC);/* Clear Transmission complete flag*/

	}
	else if(GET_BIT(UART2->SR,UARTx_SR_RXNE)==1)
	{
		UART3_CallBack(UART2->DR);
		/* Read data Register not empty(RXNE)flag Cleard by
		 * by Read UART3->DR
		 * */

	}
}
/************************************************************/
void USART3_IRQHandler(void)
{
	if(GET_BIT(UART3->SR,UARTx_SR_TC)==1)
	{
		if(Global_pu8ArryUART3[UART3_COUNTER]!='\0')
		{
			UART3->DR=Global_pu8ArryUART3[UART3_COUNTER];
			++UART3_COUNTER;
			/* Transmission complete flag Cleared by
			 * Read UART3->SR
			 * Write toUART3->DR
			 */
		}
		else
		{
			CLR_BIT(UART3->CR1,UARTx_CR1_TCIE);/* Disable interrupt */
			UART1_COUNTER=1;
		}

		CLR_BIT(UART3->SR,UARTx_SR_TC);/* Clear Transmission complete flag*/

	}
	else if(GET_BIT(UART3->SR,UARTx_SR_RXNE)==1)
	{
		UART3_CallBack(UART3->DR);
		/* Read data Register not empty(RXNE)flag Cleard by
		 * by Read UART3->DR
		 * */

	}
}

