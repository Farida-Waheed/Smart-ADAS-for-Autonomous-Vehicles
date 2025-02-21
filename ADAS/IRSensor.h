/*
 * IRSensor.h
 *
 * Created: 9/1/2024 9:15:41 PM
 *  Author: Farid
 */ 


#ifndef IRSENSOR_H
#define IRSENSOR_H

#include <avr/io.h>

// Define pins for IR sensors
#define IR_LEFT_PIN   PB1
#define IR_RIGHT_PIN  PB0
#define IR_PORT       PORTB
#define IR_DDR        DDRB
#define IR_PIN        PINB

// Function prototypes and implementations

void IRSensor_Init(void) {
	IR_DDR &= ~((1 << IR_LEFT_PIN) | (1 << IR_RIGHT_PIN)); // Set IR pins as input
}

uint8_t IRSensor_ReadLeft(void) {
	return (IR_PIN & (1 << IR_LEFT_PIN)) ? 1 : 0;
}

uint8_t IRSensor_ReadRight(void) {
	return (IR_PIN & (1 << IR_RIGHT_PIN)) ? 1 : 0;
}

#endif // IRSENSOR_H
