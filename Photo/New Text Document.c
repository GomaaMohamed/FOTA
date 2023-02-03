
void TETRIS_voidDrawBlock(u16 x,u16 y)
{

	TFT_voidDrawRectangle(x,x+8,y,y+8,0xf800);

}
void TETRIS_voidDeleteBlock(u16 x,u16 y)
{

	TFT_voidDrawRectangle(x,x+8,y,y+8,0x07e0);
}


void TETRIS_voidDeleteShape(u16 x,u16 y,u8 shape)
{
	switch (shape)
	{
		case 1:    TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x+10,y);    TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x+10,y-10);  break;
		case 2:    TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x+10,y);    TETRIS_voidDeleteBlock(x+20,y);    TETRIS_voidDeleteBlock(x+30,y);     break;
		case 3:    TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x,y-20);    TETRIS_voidDeleteBlock(x,y-30);     break;
		case 4:    TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x+10,y-10); TETRIS_voidDeleteBlock(x+10,y);    TETRIS_voidDeleteBlock(x+20,y);     break;
		case 5:    TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x+10,y-10); TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x,y-20);     break;
		case 6:    TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x-10,y-10); TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x,y-20);     break;
		case 7:    TETRIS_voidDeleteBlock(x-10,y-10); TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x+10,y-10);  break;
		case 8:    TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x,y-20);    TETRIS_voidDeleteBlock(x+10,y);     break;
		case 9:    TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x+10,y-10); TETRIS_voidDeleteBlock(x+20,y-10);  break;
		case 10:   TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x,y-20);    TETRIS_voidDeleteBlock(x-10,y-20);  break;
		case 11:   TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x+10,y);    TETRIS_voidDeleteBlock(x+20,y);    TETRIS_voidDeleteBlock(x+20,y-10);  break;
		case 12:   TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x+10,y);    TETRIS_voidDeleteBlock(x+10,y-10); TETRIS_voidDeleteBlock(x+10,y-20);  break;
		case 13:   TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x+10,y);    TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x,y-20);     break;
		case 14:   TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x,y-20);    TETRIS_voidDeleteBlock(x+10,y-20);  break;
		case 15:   TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x+10,y);    TETRIS_voidDeleteBlock(x+20,y);     break;
		case 16:   TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x+10,y-10); TETRIS_voidDeleteBlock(x+10,y-20);  break;
		case 17:   TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x+10,y);    TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x-10,y-10);  break;
		case 18:   TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x,y-10);    TETRIS_voidDeleteBlock(x-10,y-10); TETRIS_voidDeleteBlock(x-10,y-20);  break;
		case 19:   TETRIS_voidDeleteBlock(x,y);       TETRIS_voidDeleteBlock(x+10,y);    TETRIS_voidDeleteBlock(x+10,y-10); TETRIS_voidDeleteBlock(x+20,y-10);  break;
	}                                                          
}

void TETRIS_voidDrawShape(u16 x,u16 y,u8 shape)
{
	switch (shape)
	{
		case 1:    TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x+10,y);    TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x+10,y-10);  break;
		case 2:    TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x+10,y);    TETRIS_voidDrawBlock(x+20,y);    TETRIS_voidDrawBlock(x+30,y);     break;
		case 3:    TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x,y-20);    TETRIS_voidDrawBlock(x,y-30);     break;
		case 4:    TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x+10,y-10); TETRIS_voidDrawBlock(x+10,y);    TETRIS_voidDrawBlock(x+20,y);     break;
		case 5:    TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x+10,y-10); TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x,y-20);     break;
		case 6:    TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x-10,y-10); TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x,y-20);     break;
		case 7:    TETRIS_voidDrawBlock(x-10,y-10); TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x+10,y-10);  break;
		case 8:    TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x,y-20);    TETRIS_voidDrawBlock(x+10,y);     break;
		case 9:    TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x+10,y-10); TETRIS_voidDrawBlock(x+20,y-10);  break;
		case 10:   TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x,y-20);    TETRIS_voidDrawBlock(x-10,y-20);  break;
		case 11:   TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x+10,y);    TETRIS_voidDrawBlock(x+20,y);    TETRIS_voidDrawBlock(x+20,y-10);  break;
		case 12:   TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x+10,y);    TETRIS_voidDrawBlock(x+10,y-10); TETRIS_voidDrawBlock(x+10,y-20);  break;
		case 13:   TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x+10,y);    TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x,y-20);     break;
		case 14:   TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x,y-20);    TETRIS_voidDrawBlock(x+10,y-20);  break;
		case 15:   TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x+10,y);    TETRIS_voidDrawBlock(x+20,y);     break;
		case 16:   TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x+10,y-10); TETRIS_voidDrawBlock(x+10,y-20);  break;
		case 17:   TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x+10,y);    TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x-10,y-10);  break;
		case 18:   TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x,y-10);    TETRIS_voidDrawBlock(x-10,y-10); TETRIS_voidDrawBlock(x-10,y-20);  break;
		case 19:   TETRIS_voidDrawBlock(x,y);       TETRIS_voidDrawBlock(x+10,y);    TETRIS_voidDrawBlock(x+10,y-10); TETRIS_voidDrawBlock(x+20,y-10);  break;
	}                                                          
}