/*******************************************/
/* Author:Hussin Ebrahim                   */
/* Date  :20/9/2020                        */
/* Versin:V01                              */
/*******************************************/
#ifndef       UART_CONFIG_H
#define       UART_CONFIG_H
/*   F(APB2=8MHZ) , Baud Rate=9800  
*    mantissa=d52 =0x0340 
*    Fraction=(.083*16)=(1.32)(~=d1)=(0x0001)
*/
#define   UARTx_BAUD_RATE       0x0045

/* Option For Word Length:
	UART_1_START_BIT_8_DATA_BITS
	UART_1_START_BIT_9_DATA_BITS
  
*/
#define  UARTx_WORD_LENGHT         UARTx_1_START_BIT_8_DATA_BITS

/* Option for Parity :
	UARTx_PARITY_ENABLE
	UARTx_PARITY_DISABLE
*/	
#define  UARTx_PARITY_CONTROL      UARTx_PARITY_DISABLE


/* Option for Parity Selection:
	UARTx_EVEN_PARITY
	UARTx_ODD_PARITY
*/
/* Select value if Parity is enable */
#if      UARTx_PARITY_CONTROL==UART_PARITY_ENABLE
#define  UARTx_PARITY_SELECTION   UART_EVEN_PARITY
#endif 

/* Option for No of Stop Bits	
*   UARTx_1_STOP_BIT
*   UARTx_2_STOP_BIT
*/
#define  UARTx_STOP_BIT_NO     UART_1_STOP_BIT
#endif








