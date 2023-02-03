/***************************************/
/* Author  :Gomaa                      */
/* Date    :7 Seb 2020                 */
/* Version :V01                        */
/***************************************/

#ifndef _DAC_PRIVATE_H
#define _DAC_PRIVATE_H

#define DAC_PORTA  0
#define DAC_PORTB  1
#define DAC_PORTC  2


static volatile u8 *Samples = 0;
static volatile u32 NumOfSamples = 0;
static volatile u16 TicksOfConversion = 0;
static volatile u32 counter = 0;

static void SetDac(void);




#endif
