/***************************************/
/* Author  :Gomaa                      */
/* Date    :2 Seb 2020                 */
/* Version :V01                        */
/***************************************/

#ifndef _IR_PRIVATE_H_
#define _IR_PRIVATE_H_

/* Line Definition */
#define   IR_LINE0    0
#define   IR_LINE1    1		 
#define   IR_LINE2    2		 
#define   IR_LINE3    3		 
#define   IR_LINE4    4		 
#define   IR_LINE5    5		 
#define   IR_LINE6    6		 
#define   IR_LINE7    7		 
#define   IR_LINE8    8		 
#define   IR_LINE9    9		 
#define   IR_LINE10   10		 
#define   IR_LINE11   11		 
#define   IR_LINE12   12		 
#define   IR_LINE13   13		 
#define   IR_LINE14   14		 
#define   IR_LINE15   15	

/* PORT Definition */
#define    IR_PORTA   0	 
#define    IR_PORTB   1		 
#define    IR_PORTC   2

volatile u32 FramData[50];
volatile u8  flag = 0;
volatile u8  edgecounter = 0;
volatile u8  Data = 0;
volatile u8  Temp;	

static void TakeAction(void);
static void GetFrame(void);


#endif
