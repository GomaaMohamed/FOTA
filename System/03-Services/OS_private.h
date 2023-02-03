/***************************************/
/* Author  :Gomaa                      */
/* Date    :5 Seb 2020                 */
/* Version :V01                        */
/***************************************/

#ifndef _OS_PRIVATE_H
#define _OS_PRIVATE_H

#define 		NULL 					(0)

#define			TASK_SUSPENDED			1

#define			TASK_READY				2


typedef struct
{
	u16 Period;
	void (*TaskHandler)(void);
	u16	firstDelay;
	u8 State;
}Task;

static Task OStasks[NUM_OF_TASKS] = {NULL};
static void SCHEDULER(void);


#endif