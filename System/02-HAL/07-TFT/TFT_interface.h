/***************************************/
/* Author  :Gomaa                      */
/* Date    :21 Seb 2020                 */
/* Version :V01                        */
/***************************************/

#ifndef _TFT_INTERFACE_H
#define _TFT_INTERFACE_H

void  TFT_voidInit(void);
void  TFT_voidDisplayImage(const u16* Copy_Image);
void  TFT_voidFillBackGround( u16 Copy_u16Color);
void  TFT_voidDrawRectangle(u8 x1,u8 x2,u8 y1,u8 y2,u16 Copy_u16Color);
void  TFT_voidWriteChar(u8 x1, u8 y1,u16 Copy_u16Color, u8 Copy_u8Char);
void  TFT_voidWriteNum(u8 x1, u8 y1,u16 Copy_u16Color, u8 Copy_u8Char);
void  TFT_voidDeleteCharNum(u8 x1, u8 y1);


#endif
