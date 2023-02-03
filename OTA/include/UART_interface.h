/*******************************************/
/* Author:Hussin Ebrahim                   */
/* Date  :20/9/2020                        */
/* Versin:V01                              */
/*******************************************/
#ifndef       UART_INTERFACE_H
#define       UART_INTERFACE_H

void UART1_voidInit(void);
void UART1_voidTransmitSynch(u8 Arr[]);
void UART1_voidTransmitASynch(u8 Arr[]);
u8   UART1_u8ReceiveSynch(u32 Copy_u32Timeout);
void UART1_voidReceiveASynch(void (* CallBack)(u8));

void UART2_voidInit(void);
void UART2_voidTransmit(u8 Arr[]);
void UART2_voidTransmitASynch(u8 Arr[]);
u8   UART2_u8ReceiveSynch(void);
void UART2_voidReceiveASynch(void (* CallBack)(u8));

void UART3_voidInit(void);
void UART3_voidTransmit(u8 Arr[]);
void UART3_voidTransmitASynch(u8 Arr[]);
u8   UART3_u8ReceiveSynch(void);
void UART3_voidReceiveASynch(void (* CallBack)(u8));
#endif
