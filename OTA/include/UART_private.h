/*******************************************/
/* Author:Hussin Ebrahim                   */
/* Date  :20/9/2020                        */
/* Versin:V01                              */
/*******************************************/
#ifndef       UART_PRIVATE_H
#define       UART_PRIVATE_H

typedef struct 
{
	volatile u32  SR   ;
	volatile u32  DR   ;
	volatile u32  BRR  ;
	volatile u32  CR1  ;
	volatile u32  CR2  ;
	volatile u32  CR3  ;
	volatile u32  GTPR ;
}UART_Register;
#define    UART1     ((UART_Register *)0x40013800)
#define    UART2     ((UART_Register *)0x40004400)
#define    UART3     ((UART_Register *)0x40004800)
/*************UART->SR*******************/
#define   UARTx_SR_TC                          6
#define   UARTx_SR_RXNE                        5

/*************UARTx->CR1******************/
#define   UARTx_CR1_UE                         13
#define   UARTx_CR1_M                          12
#define   UARTx_CR1_PCE                        10
#define   UARTx_CR1_PS                         9
#define   UARTx_CR1_TXEIE                      7
#define   UARTx_CR1_TCIE                       6
#define   UARTx_CR1_RXNEIE                     5
#define   UARTx_CR1_TE                         3
#define   UARTx_CR1_RE                         2
/************UARTx->CR2******************/
#define   UARTx_CR2_STOP                       12

/* Option For Word Length:     */
#define  	UARTx_1_START_BIT_8_DATA_BITS      0
#define  	UARTx_1_START_BIT_9_DATA_BITS      1
  
/* Option for Parity :          */
#define 	UARTx_PARITY_ENABLE                0
#define 	UARTx_PARITY_DISABLE               1 

/* Option for Parity Selection:  */
#define 	UARTx_EVEN_PARITY                  0
#define 	UARTx_ODD_PARITY                   1

/* Option for No of Stop Bits	 */
#define     UARTx_1_STOP_BIT                   0b00
#define     UARTx_2_STOP_BIT                   0b10

static u8* Global_pu8ArryUART1=NULL;
static u8* Global_pu8ArryUART2=NULL;
static u8* Global_pu8ArryUART3=NULL;

static u8 UART1_COUNTER=1;
static u8 UART2_COUNTER=1;
static u8 UART3_COUNTER=1;

void (*UART1_CallBack)(u8)=NULL;
void (*UART2_CallBack)(u8)=NULL;
void (*UART3_CallBack)(u8)=NULL;
#endif
