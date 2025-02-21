/*
 * Functions.h
 *
 * Created: 9/1/2024 9:23:52 PM
 *  Author: Farid
 */ 


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

void ACC_Update(void) {
	uint32_t distance = UltrasonicSensor_GetDistance();
	if (distance <= 10 && distance >= 5) { 
		MotorDriver_SetSpeed(distance - 5,distance - 5);
		LCD_Command(0x01);
		LCD_Command(0x80);
		LCD_Data_String("Obstacle ");
		LCD_Command(0xC0);
		LCD_Data_String("detected!!!");
		_delay_ms(50);
		LCD_Command(0x01);
		} 
		else {
		MotorDriver_SetSpeed(distance - 5,distance - 5); // Adjust speed as needed
		LCD_Command(0x01);
		LCD_Command(0x80);
		LCD_Data_String("Cruising");
		_delay_ms(50);
		LCD_Command(0x01);
	}
}


void LDW_Update(void) {
	if (IRSensor_ReadLeft() == 1) 
	{ 
		Buzzer_On();
		LCD_Command(0x01);
		LCD_Command(0x80);
		LCD_Data_String("Left lane ");
		LCD_Command(0xC0);
		LCD_Data_String("departure!");
		LCD_Command(0x01);
		}
		 else if (IRSensor_ReadRight() == 1) 
		{  // Right lane departure detected
		Buzzer_On();
		LCD_Command(0x01);
		LCD_Command(0x80);
		LCD_Data_String("Right lane ");
		LCD_Command(0xC0);
		LCD_Data_String("departure!");
		LCD_Command(0x01);
		} 
		else 
		{
		LCD_Command(0x01);
		LCD_Command(0x80);
		LCD_Data_String("Lane!");
		Buzzer_Off();
	}
}


void AEB_Update(void) {
	uint32_t distance = UltrasonicSensor_GetDistance();

	if (distance < 5) {  // Critical distance, activate emergency braking
		MotorDriver_Stop();
		Buzzer_On();
		LCD_Command(0x01);
		LCD_Data_String("Emergency ");
		LCD_Command(0xC0);
		LCD_Data_String("Braking!!!!!");
		} else {
		Buzzer_Off();
	}
}


void LKS_Update(void) {
	if (IRSensor_ReadLeft() == 1) {  // Left lane departure detected
		MotorDriver_SetDirection(1); // Adjust vehicle direction to right
		LCD_Command(0x01);
		LCD_Data_String("Adjusting right...");
		} else if (IRSensor_ReadRight() == 1) {  // Right lane departure detected
		MotorDriver_SetDirection(0); // Adjust vehicle direction to left
		LCD_Command(0x01);
		LCD_Data_String("Adjusting left...");
	}
}

#endif /* FUNCTIONS_H_ */