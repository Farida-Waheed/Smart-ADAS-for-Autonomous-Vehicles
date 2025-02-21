

#ifndef MOTORDRIVER_H_
#define MOTORDRIVER_H_

#include <avr/io.h>
#include "UltrasonicSensor.h"

// Define pins for Motor Driver (L298N)
#define MOTOR_ENA_PIN   PB3  // Enable pin for motor A (connected to OCR0A)
#define MOTOR_ENB_PIN   PD7  // Enable pin for motor B (connected to OCR0B)
#define MOTOR_IN1_PIN   PC2  // Input 1 for motor A
#define MOTOR_IN2_PIN   PC3  // Input 2 for motor A
#define MOTOR_IN3_PIN   PC4  // Input 1 for motor B
#define MOTOR_IN4_PIN   PC5  // Input 2 for motor B
#define MOTOR_PORT      PORTC
#define MOTOR_DDR       DDRC
#define PWM_PORT        PORTD
#define PWM_DDR         DDRD

// Define motor directions
#define FORWARD  1
#define BACKWARD 2
#define LEFT     3
#define RIGHT    4

// Function prototypes
void MotorDriver_Init(void);
void MotorDriver_SetSpeed(uint8_t speedPercentA, uint8_t speedPercentB);
void MotorDriver_SetDirection(uint8_t direction);
void MotorDriver_Stop(void);

// Function implementations

void MotorDriver_Init(void) {
	// Set motor control pins as output
	MOTOR_DDR |= (1 << MOTOR_IN1_PIN) | (1 << MOTOR_IN2_PIN) |
	(1 << MOTOR_IN3_PIN) | (1 << MOTOR_IN4_PIN);
	
	// Set PWM pins as output
	PWM_DDR |= (1 << MOTOR_ENB_PIN);
	DDRB |= (1 << MOTOR_ENA_PIN);
	
	// Initialize Timer0 for PWM
	TCCR0 |= (1 << WGM00) | (1 << WGM01);
	TCCR0 |= (1 << COM01);
	TCCR0 |= (1 << CS01);

	TCCR2 |= (1 << WGM20) | (1 << WGM21);
	TCCR2 |= (1 << COM21);
	TCCR2|= (1 << CS21);
	// Initialize the motors in a stopped state
	//MotorDriver_Stop();
}

void MotorDriver_SetSpeed(uint8_t speedPercentA, uint8_t speedPercentB) {
	OCR0 = speedPercentA  ;  // Set speed for motor A
	OCR2 = speedPercentB  ;  // Set speed for motor B
}

void MotorDriver_SetDirection(uint8_t direction) {
	uint32_t distance = UltrasonicSensor_GetDistance();
	switch(direction) {
		case FORWARD:
		MOTOR_PORT |= (1 << MOTOR_IN1_PIN);
		MOTOR_PORT &= ~(1 << MOTOR_IN2_PIN);
		MOTOR_PORT |= (1 << MOTOR_IN3_PIN);
		MOTOR_PORT &= ~(1 << MOTOR_IN4_PIN);
		break;
		case BACKWARD:
		MOTOR_PORT &= ~(1 << MOTOR_IN1_PIN);
		MOTOR_PORT |= (1 << MOTOR_IN2_PIN);
		MOTOR_PORT &= ~(1 << MOTOR_IN3_PIN);
		MOTOR_PORT |= (1 << MOTOR_IN4_PIN);
		break;
		case LEFT:
		MotorDriver_SetSpeed(distance, distance - 100);
		break;
		case RIGHT:
		MotorDriver_SetSpeed(distance - 100, distance);
		break;
		default:
		MotorDriver_Stop();  // Stop motors if an invalid direction is provided
		break;
	}
}

void MotorDriver_Stop(void) {
	MOTOR_PORT &= ~((1 << MOTOR_IN1_PIN) | (1 << MOTOR_IN2_PIN) |
	(1 << MOTOR_IN3_PIN) | (1 << MOTOR_IN4_PIN)); // Stop motors
}

#endif // MOTORDRIVER_H_