/*
 * prog.c
 *
 *  Created on: Dec 30, 2022
 *      Author: Gamal Ezzat
 */

#include "..\..\LIB\STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "..\..\MCAL\DIO\DIO_interface.h"
#include "util/delay.h"
#include "CLCD_interface.h"
#include "CLCD_Config.h"
#include "CLCD_private.h"


void CLCD_VidInt(void)
{
	/************	SET CLCD PINS DIRECTION 8PIT MODE	*********************/
	DIO_u8SetPortDirection(CLCD_DATA_PORT,DIO_PORT_OUTPUT);
	DIO_u8SetPinDirection(CLCD_RS_PORT, CLCD_RS_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_OUTPUT);
	/************************************************************************/





	/************************************************************************/
	_delay_ms(30);
	CLCD_VidSendComm(HCLCD_FUNCTION_SET);
	_delay_ms(1);
	CLCD_VidSendComm(HCLCD_Display_On_Off);
	_delay_ms(1);
	CLCD_VidSendComm(DISPLAY_CLEAR);
	_delay_ms(1);
	CLCD_VidSendComm(HCLCD_ENTRY_MODE_SET);
	/************************************************************************/


}

void CLCD_VidSendComm(u8 Copt_u8Command)
{

	/*				Set RS Pin To Low For Commend			  */
	DIO_u8SetPinValue(CLCD_RS_PORT, CLCD_RS_PIN, DIO_PIN_LOW);

	/*				Set RW Pin To Low For Write 			  */
	//DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_PIN_LOW);

	/*				Set Commend To Data Port				*/
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copt_u8Command);

	/*				Set E Pin To HIGH FOR PULSE 			  */
	DIO_u8SetPinValue(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_HIGH);

	_delay_ms(1);
	/*				Set E Pin To Low For PULSE 			  */
	DIO_u8SetPinValue(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_LOW);

}

void CLCD_VidSendchar(u8 Copt_u8Data)
{

	/*				Set RS Pin To HIGH For Data			  */
	DIO_u8SetPinValue(CLCD_RS_PORT, CLCD_RS_PIN, DIO_PIN_HIGH);

	/*				Set RW Pin To Low For Write 			  */
	//DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_PIN_LOW);

	/*				Set Commend To Data Port				*/
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copt_u8Data);

	/*				Set E Pin To Low For Write 			  */
	DIO_u8SetPinValue(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_HIGH);

	_delay_ms(1);
	/*				Set E Pin To Low For PULSE 			  */
	DIO_u8SetPinValue(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_LOW);


}

void CLCD_VidSendString(  char  Copy_Pu8String[])
{
#if CLCD_u8Mode == CLCD_u8_MODE_8BIT
	u8 Local_u8Counter=0;
	while(Copy_Pu8String[Local_u8Counter]!='\0')
	{
		CLCD_VidSendchar(Copy_Pu8String[Local_u8Counter]);
		Local_u8Counter++;
	}
#elif CLCD_u8Mode == CLCD_u8_MODE_4BIT

	u8 Local_u8Counter=0;
	while(Copy_Pu8String[Local_u8Counter]!='\0')
	{
		CLCD_VidSendchar4bit(Copy_Pu8String[Local_u8Counter]);
		Local_u8Counter++;
	}
#endif
}

void CLCD_VidGoToXY(u8 Copy_u8LineNum, u8 Copy_u8Location)
{

#if CLCD_u8Mode == CLCD_u8_MODE_8BIT

	if(Copy_u8LineNum <=LCD_u8_LINE4)
	{
		switch(Copy_u8LineNum)
		{
		case LCD_u8_LINE1:CLCD_VidSendComm(0x80+Copy_u8Location);break;
		case LCD_u8_LINE2:CLCD_VidSendComm(0xc0+Copy_u8Location);break;
		case LCD_u8_LINE3:CLCD_VidSendComm(0x94+Copy_u8Location);break;
		case LCD_u8_LINE4:CLCD_VidSendComm(0xd4+Copy_u8Location);break;
		default:;

		}
	}
#elif CLCD_u8Mode == CLCD_u8_MODE_4BIT
	if(Copy_u8LineNum <=LCD_u8_LINE4)
	{
		switch(Copy_u8LineNum)
		{
		case LCD_u8_LINE1:CLCD_VidSendComm4bit(0x80+Copy_u8Location);break;
		case LCD_u8_LINE2:CLCD_VidSendComm4bit(0xc0+Copy_u8Location);break;
		case LCD_u8_LINE3:CLCD_VidSendComm4bit(0x94+Copy_u8Location);break;
		case LCD_u8_LINE4:CLCD_VidSendComm4bit(0xd4+Copy_u8Location);break;
		default:;

		}
	}
#endif

}

void CLCD_VidSendNum(u32 Copy_u32Numper)
{

		u8 LOC_u8ArrayReversedNumber[10];
		u8 LOC_u8NumberCounter=0;
		s8 LOC_s8SendCharLoopCounter;

		while(Copy_u32Numper>0)
		{
			LOC_u8ArrayReversedNumber[LOC_u8NumberCounter]=Copy_u32Numper%10;
			Copy_u32Numper/=10;
			LOC_u8NumberCounter++;
		}

		LOC_s8SendCharLoopCounter=LOC_u8NumberCounter-1;
	#if CLCD_u8Mode == CLCD_u8_MODE_8BIT

		while(LOC_s8SendCharLoopCounter>=0)
		{
			switch((LOC_u8ArrayReversedNumber[LOC_s8SendCharLoopCounter]))
			{
			case 0: CLCD_VidSendchar('0'); break;
			case 1: CLCD_VidSendchar('1'); break;
			case 2: CLCD_VidSendchar('2'); break;
			case 3: CLCD_VidSendchar('3'); break;
			case 4: CLCD_VidSendchar('4'); break;
			case 5: CLCD_VidSendchar('5'); break;
			case 6: CLCD_VidSendchar('6'); break;
			case 7: CLCD_VidSendchar('7'); break;
			case 8: CLCD_VidSendchar('8'); break;
			case 9: CLCD_VidSendchar('9'); break;
			default:break;
			}
			LOC_s8SendCharLoopCounter--;
		}
	#elif CLCD_u8Mode == CLCD_u8_MODE_4BIT
		while(LOC_s8SendCharLoopCounter>=0)
		{
			switch((LOC_u8ArrayReversedNumber[LOC_s8SendCharLoopCounter]))
			{
			case 0: CLCD_VidSendchar4bit('0'); break;
			case 1: CLCD_VidSendchar4bit('1'); break;
			case 2: CLCD_VidSendchar4bit('2'); break;
			case 3: CLCD_VidSendchar4bit('3'); break;
			case 4: CLCD_VidSendchar4bit('4'); break;
			case 5: CLCD_VidSendchar4bit('5'); break;
			case 6: CLCD_VidSendchar4bit('6'); break;
			case 7: CLCD_VidSendchar4bit('7'); break;
			case 8: CLCD_VidSendchar4bit('8'); break;
			case 9: CLCD_VidSendchar4bit('9'); break;
			default:break;
			}
			LOC_s8SendCharLoopCounter--;
		}
	#endif
}

void CLCD_LocalSendBit(u8 Copy_u8Val)
{
	//	Store Evrey Port For each Pin Endividual
	u8 Local_ArrPort[]={CLCD_DATA_PORT_PIN4,CLCD_DATA_PORT_PIN5,CLCD_DATA_PORT_PIN6,CLCD_DATA_PORT_PIN7};

	//	Store Evrey  each Pin Endividual
	u8 Local_ArrPin[]={CLCD_DATA_PIN4,CLCD_DATA_PIN5,CLCD_DATA_PIN6,CLCD_DATA_PIN7};

	// Store Lest Sig Bit Values
	u8 Local_ArrLSBVal[4];

	for(u8 i=0;i<4;i++)
	{Local_ArrLSBVal[i]=GET_BIT(Copy_u8Val,i);}

	for(u8 i=0;i<4;i++)
	{
		if(Local_ArrLSBVal[i]==1)
			{DIO_u8SetPinValue(Local_ArrPort[i], Local_ArrPin[i], DIO_PIN_HIGH);}
		else
			{DIO_u8SetPinValue(Local_ArrPort[i], Local_ArrPin[i], DIO_PIN_LOW);}
	}



}
void CLCD_VidInt4bit(void)
{
	/*********************************************************************/
	/*	1- Power ON
	 *	2- Delay 30ms or more
	 * 	3-Function Set 		000010xxxx
	 * 				 	    000010xxxx
	 * 					    0011xxxxxx
	 * 	4- Delay 1ms
	 * 	5- Display Control  0000xxxx
	 * 						1111xxxx
	 * 	6- Delay 1ms
	 * 	7- Display Clear
	 * 	8- Delay 2ms
	 * 	9- Entry Set Mode   000000xxxx
	 * 						000111xxxx
	 *
	 ***********************************************************************/
	DIO_u8SetPinDirection(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_RS_PORT, CLCD_RS_PIN, DIO_PIN_OUTPUT);

	DIO_u8SetPinDirection(CLCD_DATA_PORT_PIN4, CLCD_DATA_PIN4, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA_PORT_PIN5, CLCD_DATA_PIN5, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA_PORT_PIN6, CLCD_DATA_PIN6, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA_PORT_PIN7, CLCD_DATA_PIN7, DIO_PIN_OUTPUT);


	_delay_ms(30);
	//Function Set
	CLCD_VidSendComm4bit((FUNCTION_SET_4BITS_2LINES)>>4);
	CLCD_VidSendComm4bit((FUNCTION_SET_4BITS_2LINES)>>4);
	CLCD_VidSendComm4bit(FUNCTION_SET_4BITS_2LINES );

	_delay_ms(1);

	//Display Control
	CLCD_VidSendComm4bit(HCLCD_Display_On_Off>>4);
	CLCD_VidSendComm4bit((HCLCD_Display_On_Off));

	_delay_ms(1);

	//Display Clear
	CLCD_VidSendComm4bit(DISPLAY_CLEAR);

	_delay_ms(2);

	//Entry Set Mode
	CLCD_VidSendComm4bit(HCLCD_ENTRY_MODE_SET>>4);
	CLCD_VidSendComm4bit(HCLCD_ENTRY_MODE_SET);
	_delay_ms(2);

}

void CLCD_VidSendComm4bit(u8 Copt_u8Command)
{

	/*				Set RS Pin To Low For Commend			  */
	DIO_u8SetPinValue(CLCD_RS_PORT, CLCD_RS_PIN, DIO_PIN_LOW);

	/********************************************************/
	/********************************************************/

	CLCD_LocalSendBit(Copt_u8Command>>4);

	DIO_u8SetPinValue(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_LOW);
	/********************************************************/

	_delay_ms(2);

	/********************************************************/
	/********************************************************/
	CLCD_LocalSendBit((Copt_u8Command));
	DIO_u8SetPinValue(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_LOW);
	/********************************************************/
	/********************************************************/

}

void CLCD_VidSendchar4bit(u8 Copt_u8Data)
{
	/*				Set RS Pin To Low For Commend			  */
	DIO_u8SetPinValue(CLCD_RS_PORT, CLCD_RS_PIN, DIO_PIN_HIGH);

	/********************************************************/
	/********************************************************/
	CLCD_LocalSendBit( Copt_u8Data>>4);

	DIO_u8SetPinValue(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_LOW);
	/********************************************************/
	_delay_ms(2);


	/********************************************************/
	/********************************************************/
	CLCD_LocalSendBit((Copt_u8Data));

	DIO_u8SetPinValue(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(CLCD_E_PORT, CLCD_E_PIN, DIO_PIN_LOW);
	/********************************************************/
	/********************************************************/

}

void CLCD_VidClearDisplay()
{
#if CLCD_u8Mode == CLCD_u8_MODE_8BIT
	CLCD_VidSendComm(1);
#elif CLCD_u8Mode == CLCD_u8_MODE_4BIT

	CLCD_VidSendComm4bit(1);
	_delay_ms(10);

#endif
}

void CLCD_Welcome(void)
{
	CLCD_VidGoToXY(LCD_u8_LINE1,0);
	CLCD_VidSendString("Gamal Ezzat");
	CLCD_VidGoToXY(LCD_u8_LINE2,0);
	CLCD_VidSendString("Embedded System");
	CLCD_VidGoToXY(LCD_u8_LINE3,0);
	CLCD_VidSendString("Using Unordered PINS");
	CLCD_VidGoToXY(LCD_u8_LINE4,0);
	CLCD_VidSendString("Interrubt Code");
	_delay_ms(1000);
	CLCD_VidClearDisplay();

}
