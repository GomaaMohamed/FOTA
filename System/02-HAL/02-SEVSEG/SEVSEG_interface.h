/***************************************/
/* Author  :Gomaa                      */
/* Date    :13 Aug 2020                 */
/* Version :V01                        */
/***************************************/

#ifndef _SEVSEG_INTERFACE_H_
#define _SEVSEG_INTERFACE_H_

/* Num Options 
                    hgfedcba
*/
#define   ZERO    0b11000000
#define   ONE     0b11111001
#define   TWO     0b10100100
#define   THREE   0b10110000
#define   FOUR    0b10011001
#define   FIVE    0b10010010
#define   SIX     0b10000010
#define   SEVEN   0b11111000
#define   EIGHT   0b10000000
#define   NINE    0b10010000
/* Port that seven segment use
      Options:
	  GPIOA
	  GPIOB
	  GPIOC
*/
/* which half in the port that seven segment use
      Options:
	  GPIO_FIRST_HALF
	  GPIO_SECOND_HALF
*/
void SEVSEG_voidDisplayNum(u8 Copy_u8Port,u8 Copy_u8HalfPort,u8 Copy_u8Value);

#endif