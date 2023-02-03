#ifndef _TETRIS_H_
#define _TETRIS_H_

static volatile u8 x =120;
static volatile u8 y =140;

void TETRIS_voidDrawBlock(u16 x,u16 y,u16 Color);
void TETRIS_voidDeleteUnit(u16 x,u16 y);
void TETRIS_voidShiftUnitRight();
void TETRIS_voidShiftUnitLeft();
void TETRIS_voidShiftUnitDown();
void TETRIS_voidRotateUnitRight();
void TETRIS_voidRotateUnitLeft();
void TETRIS_voidCreateUnit(u16 x,u16 y);
#endif

