/***************************************/
/* Author  :Gomaa                      */
/* Date    :14 Seb 2020                 */
/* Version :V01                        */
/***************************************/

#ifndef    _STP_CONFIG_H
#define    _STP_CONFIG_H 

/* Port That we use
 * STP_PORT_AND_BUS Options:
 * RCC_APB2,RCC_IOPA
 * RCC_APB2,RCC_IOPB
 * RCC_APB2,RCC_IOPC
 */
#define    STP_PORT_AND_BUS         RCC_APB2,RCC_IOPA
/* Please Write In pairs Port and Pin */
#define    STP_SHIFT_CLOCK_PIN         GPIOA,GPIO_PIN2 
#define    STP_STORE_CLOCK_PIN         GPIOA,GPIO_PIN1
#define    STP_DATA_PIN                GPIOA,GPIO_PIN0
#define    STP_SHIFT_RESET_PIN         GPIOA,GPIO_PIN3


/* Number Of Bytes That You Need Send in One Time
 Note: This Size in case of STP_ALL_DATA_MODE  Mode */
#define     STP_DATA_SIZE    2


 


#endif







