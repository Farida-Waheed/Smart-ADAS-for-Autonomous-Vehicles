/*
 * LED_Config.h
 *
 *  Created on: Dec 30, 2022
 *      Author: gamal
 */

#ifndef COST_HAL_CLCD_CLCD_CONFIG_H_
#define COST_HAL_CLCD_CLCD_CONFIG_H_

/*	OPtions:	1- CLCD_u8_MODE_8BIT
 * 				2- CLCD_u8_MODE_4BIT*/
#define CLCD_u8Mode		CLCD_u8_MODE_4BIT

/*********************	CLCD_u8_MODE_8BIT	**************************/
#define  CLCD_DATA_PORT			DIO_PORTD

/*********************************************************************/
#define  CLCD_RS_PIN			DIO_PIN3
#define  CLCD_RS_PORT			DIO_PORTA

#define  CLCD_E_PIN			    DIO_PIN2
#define  CLCD_E_PORT			DIO_PORTA
/********************************************************************/


/*********************	CLCD_u8_MODE_4BIT	*************************/

#define CLCD_DATA_PIN4 			DIO_PIN4
#define CLCD_DATA_PORT_PIN4 	DIO_PORTA

#define CLCD_DATA_PIN5 			DIO_PIN5
#define CLCD_DATA_PORT_PIN5 	DIO_PORTA

#define CLCD_DATA_PIN6 			DIO_PIN6
#define CLCD_DATA_PORT_PIN6 	DIO_PORTA

#define CLCD_DATA_PIN7 			DIO_PIN7
#define CLCD_DATA_PORT_PIN7 	DIO_PORTA
/********************************************************************/



/**Function Set Option
** 1- FUNCTION_SET_8BITS_2LINES
** 2- FUNCTION_SET_8BITS_1LINES
** 3- FUNCTION_SET_4BITS_2LINES
** 4- FUNCTION_SET_4BITS_1LINES
**/
#define HCLCD_FUNCTION_SET	FUNCTION_SET_4BITS_2LINES


/**HCLCD_Display_On_Off
** 1- DISPLAY_ON_CURSOR_ON_BLINKING_ON
** 2- DISPLAY_ON_CURSOR_ON_BLINKING_OFF
** 3- DISPLAY_ON_CURSOR_OFF
** 4- DISPLAY_OFF
**/
#define HCLCD_Display_On_Off	DISPLAY_ON_CURSOR_ON_BLINKING_ON


/** HCLCD Entry Mode Set Options
** 1- ENTRY_MODE_SET_INCREASE_WITH_SHIFT
** 2- ENTRY_MODE_SET_INCREASE
** 3- ENTRY_MODE_SET_DECREASE_WITH_SHIFT
** 4- ENTRY_MODE_SET_DECREASE
**/
#define HCLCD_ENTRY_MODE_SET	ENTRY_MODE_SET_INCREASE

#endif /* COST_HAL_LED_LED_CONFIG_H_ */
