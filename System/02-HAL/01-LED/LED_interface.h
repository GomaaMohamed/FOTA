/***************************************/
/* Author  :Gomaa                      */
/* Date    :13 Aug 2020                 */
/* Version :V01                        */
/***************************************/

#ifndef  _LED_INTERFACE_H
#define  _LED_INTERFACE_H

/* Port Id OPtions:
  GPIOA   
  GPIOB   
  GPIOC   
*/
/* Pin Id Options: 
   GPIO_PIN0     
   GPIO_PIN1    
   GPIO_PIN2     
   GPIO_PIN3     
   GPIO_PIN4     
   GPIO_PIN5     
   GPIO_PIN6     
   GPIO_PIN7     
   GPIO_PIN8     
   GPIO_PIN9     
   GPIO_PIN10    
   GPIO_PIN11    
   GPIO_PIN12 
   GPIO_PIN13   
   GPIO_PIN14   
   GPIO_PIN15   
*/

void LED_voidOn(u8 Copy_u8Port,u8 Copy_u8Pin);
void LED_voidOff(u8 Copy_u8Port,u8 Copy_u8Pin);


#endif