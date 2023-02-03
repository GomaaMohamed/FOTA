/****************************************************/
/* Author    : Hussin Ebrahim                       */
/* Version   : V03                                  */
/* Date      : 8 August 2020                        */
/* LOG       :V01  -> Initial Creation              */
/*           :V02  ->Add to  APB1&APB2  Macro       */
/*           :V03  ->Add to  Update APB1&APB2  Macro*/ 
/****************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB       0 
#define RCC_APB1      1
#define RCC_APB2      2

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
/***************APB1*************************/
#define      RCC_APB1_UART2         17
#define      RCC_APB1_UART3         18
#define      RCC_APB1_UART4         19
#define      RCC_APB1_UART5         20

/***************APB2*************************/
#define      RCC_APB2_PORTA         2
#define      RCC_APB2_PORTB         3
#define      RCC_APB2_PORTC         4

#define      RCC_APB2_SPI1          12
#define      RCC_APB2_UART1         14
#define      RCC_APB2_AFIO          0
#endif
