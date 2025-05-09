/*
 * int.h
 *
 *  Created on: Dec 30, 2022
 *      Author: gamal
 */

#ifndef COST_HAL_CLCD_CLCD_INTERFACE_H_
#define COST_HAL_CLCD_CLCD_INTERFACE_H_

#define LCD_u8_LINE1	1
#define LCD_u8_LINE2	2
#define LCD_u8_LINE3	3
#define LCD_u8_LINE4	4

#define DISPLAY_CLEAR		0b00000001


void CLCD_VidInt(void);

void CLCD_VidSendComm(u8 Copt_u8Command);

void CLCD_VidSendchar(u8 Copt_u8Data);

void CLCD_Welcome(void);

void CLCD_VidInt4bit(void);

void CLCD_VidSendComm4bit(u8 Copt_u8Command);

void CLCD_VidSendchar4bit(u8 Copt_u8Data);


void CLCD_LocalSendBit(u8 Copy_u8Val);

void CLCD_VidSendNum(u32 Copt_u32Numper);

void CLCD_VidSendString( char Copy_Pu8String[]);

void CLCD_VidGoToXY(u8 Copy_u8LineNum, u8 Copy_u8Location);
void CLCD_VidClearDisplay(void);

#endif /* COST_HAL_CLCD_CLCD_INTERFACE_H_ */
