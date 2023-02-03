/***************************************/
/* Author  :Gomaa                      */
/* Date    :14 Seb 2020                 */
/* Version :V01                        */
/***************************************/

#ifndef _STP_INTERFACE_H
#define _STP_INTERFACE_H

void STP_voidInit(void);

/* Note: One Call of this Function Send one Byte.
 * if you need send more than One Byte you must call the function no.of times equal no.of Bytes
 * ex: to send 3 Bytes you must call the function three times
 */
void STP_voidSendSyncronous(u8 Copy_u8DataToSend,u8 Copy_u8Mode);

/* STP_SINGLE_BYTE_MODE: After Every Call, Move Value From Shift Register
 * to Store Register
 * STP_ALL_DATA_MODE : After  last Call All, Data that stored in all  Shift Registers
 * will become in Store Registers
 */
void STP_voidResetShiftRegister(void);
void STP_voidSetShiftRegister(void);
#define    STP_SINGLE_BYTE_MODE   0
#define    STP_ALL_DATA_MODE      1

#endif
