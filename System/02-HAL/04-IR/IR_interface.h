/***************************************/
/* Author  :Gomaa                      */
/* Date    :2  Seb 2020                 */
/* Version :V01                        */
/***************************************/

#ifndef  _IR_INTERFACE_H
#define  _IR_INTERFACE_H
/* Return Values Of IR_u8ReturnActiveButton */
#define   IR_ON_OFF           69
#define   IR_MODE             70
#define   IR_MUTE             71
#define   IR_PAUSE_RESUME     68
#define   IR_LEFT             64
#define   IR_RIGHT            67
#define   IR_EQ               7
#define   IR_VOL_MINUS        21   
#define   IR_VOL_PLUS         9
#define   IR_RPT              25
#define   IR_U_SD             13
#define   IR_ZERO             22
#define   IR_ONE              12
#define   IR_TWO              24
#define   IR_THREE            94
#define   IR_FOUR             8
#define   IR_FIVE             28
#define   IR_SIX              90
#define   IR_SEVEN            66
#define   IR_EIEGHT           82
#define   IR_NINE             74

void IR_voidIRInit(void);
u8   IR_u8ReturnActiveButton(void);




#endif