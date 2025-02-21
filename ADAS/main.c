/*
 * main.c
 *
 * Created: 9/1/2024 9:13:09 PM
 *  Author: Farid
 */ 

#define F_CPU 8000000UL  // Define CPU frequency as 16 MHz
#include <avr/io.h>
#include <util/delay.h>
#include "IRSensor.h"
#include "Buzzer.h"
#include "UltrasonicSensor.h"
#include "Functions.h"
#include "LCD.h"
#include "MotorDriver.h"


int main(void)
 { 
 	LCD_init();
	IRSensor_Init();
	UltrasonicSensor_Init();
	Buzzer_Init();
	MotorDriver_Init();

	while (1) 
	
	{
		char buffer[17];
		uint32_t distance = UltrasonicSensor_GetDistance();
		snprintf(buffer, sizeof(buffer), "%d",distance);
		LCD_Data_String("Distance : ");
		LCD_Data_String(buffer);
		_delay_ms(50);
		LCD_Command(0x01);
		LCD_Data_String("Speed : ");
		snprintf(buffer, sizeof(buffer), "%d",distance - 5);
		LCD_Data_String(buffer);
		_delay_ms(50);
		LCD_Command(0x01);
		
		
		ACC_Update();
		_delay_ms(50);
		LDW_Update();
		_delay_ms(50);
		AEB_Update();
		_delay_ms(50);
		LKS_Update();
		_delay_ms(50);
		
		
	}
}

