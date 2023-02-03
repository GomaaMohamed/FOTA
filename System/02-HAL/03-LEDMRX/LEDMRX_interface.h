/***************************************/
/* Author  :Gomaa                      */
/* Date    :31 Aug 2020                 */
/* Version :V01                        */
/***************************************/

#ifndef  _LEDMRX_INTERFACE_H_
#define  _LEDMRX_INTERFACE_H_

void LEDMRX_voidTest(void);
void LEDMRX_voidInit(void);
/* Note: Data Size = 8 Byte */
void LEDMRX_voidDisplay(u8 *Copy_u8Data);
/* Note: Frame Size Contain Charcters each one = 8 Byte
    Frame Must Start and end With {0,0,0,0,0,0,0,0,.....,0,0,0,0,0,0,0,0}
   */
void LEDMRX_voidDisplayFrame(u8 *Copy_u8FrameData,u8 Copy_u8FrameSize);


#endif
