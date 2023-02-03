/***************************************/
/* Author  :Gomaa                      */
/* Date    :7 Seb 2020                 */
/* Version :V01                        */
/***************************************/

#ifndef _DAC_INTERFACE_H
#define _DAC_INTERFACE_H

void DAC_voidDacInit(void);
void DAC_voidSetDAC(u8 *Copy_u8Samples,u32 Copy_u32NumOfSamples,u16 Copy_u16TicksOfConversion);
void DAC_voidStartDAC(void);


#endif
