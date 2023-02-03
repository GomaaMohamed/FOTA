
#include  "STD_TYPES.h"
#include  "BIT_MATH.h"



#include  "TETRIS.h"
#include  "TFT_interface.h"


void TETRIS_voidDrawBlock(u16 x,u16 y,u16 Color)
{

	TFT_voidDrawRectangle(x,x+8,y,y+8,Color);

}
void TETRIS_voidCreateUnit(u16 x,u16 y){
    TETRIS_voidDrawBlock(x,y,0xf800);
	TETRIS_voidDrawBlock(x,y+10,0xf800);
	TETRIS_voidDrawBlock(x,y+20,0xf800);}
void TETRIS_voidDeleteUnit(u16 x,u16 y)
{

	TFT_voidDrawRectangle(x,x+8,y,y+8,0x07e0);
	TFT_voidDrawRectangle(x+10,x+18,y,y+8,0x07e0);
	TFT_voidDrawRectangle(x+20,x+28,y,y+8,0x07e0);

	TFT_voidDrawRectangle(x,x+8,y+10,y+18,0x07e0);
	TFT_voidDrawRectangle(x+10,x+18,y+10,y+18,0x07e0);
	TFT_voidDrawRectangle(x+20,x+28,y+10,y+18,0x07e0);

	TFT_voidDrawRectangle(x,x+8,y+20,y+28,0x07e0);
	TFT_voidDrawRectangle(x+10,x+18,y+20,y+28,0x07e0);
	TFT_voidDrawRectangle(x+20,x+28,y+20,y+28,0x07e0);
}
void TETRIS_voidShiftUnitRight()
{  if(x==0 ){TETRIS_voidDeleteUnit(x,y);x=120;}
	TETRIS_voidDeleteUnit(x,y);
	x=x-10;
	TETRIS_voidCreateUnit(x,y);


	}

void TETRIS_voidShiftUnitLeft()
{ if(x==120 ){TETRIS_voidDeleteUnit(x,y);x=0;}
TETRIS_voidDeleteUnit(x,y);
x=x+10;
TETRIS_voidCreateUnit(x,y);

}
void TETRIS_voidShiftUnitDown()
{ if(y==0 ){y=140;x=60;TETRIS_voidCreateUnit(x,y);}
TETRIS_voidDeleteUnit(x,y);
y=y-10;
TETRIS_voidCreateUnit(x,y);



}
void TETRIS_voidRotateUnitRight(){}
void TETRIS_voidRotateUnitLeft(){}
