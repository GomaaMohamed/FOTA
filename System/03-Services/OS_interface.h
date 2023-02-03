/***************************************/
/* Author  :Gomaa                      */
/* Date    :5 Seb 2020                 */
/* Version :V01                        */
/***************************************/

#ifndef _OS_INTERFACE_H
#define _OS_INTERFACE_H


void OS_voidCreateTask(u8 Copy_u8TaskID,u16 period,void (*ptr)(void),u16 Copy_u16firstDelay);
void OS_voidStart(void);

void OS_voidSuspendTask(u8 Copy_u8TaskID);
void OS_voidResumeTask(u8 Copy_u8TaskID);
void OS_voidDeleteTask(u8 Copy_u8TaskID);


#endif