/*
 * UltrasonicSensor.h
 *
 * Created: 9/1/2024 9:20:11 PM
 *  Author: Farid
 */ 


#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <avr/io.h>
#include <util/delay.h>

// Define pins for Ultrasonic Sensor (HC-SR04)
#define ULTRASONIC_TRIG_PIN  PC0
#define ULTRASONIC_ECHO_PIN  PC1
#define ULTRASONIC_PORT      PORTC
#define ULTRASONIC_DDR       DDRC
#define ULTRASONIC_PIN       PINC

// Function prototypes and implementations

void UltrasonicSensor_Init(void) {
	ULTRASONIC_DDR |= (1 << ULTRASONIC_TRIG_PIN);  // Set TRIG as output
	ULTRASONIC_DDR &= ~(1 << ULTRASONIC_ECHO_PIN); // Set ECHO as input
}

uint32_t UltrasonicSensor_GetDistance(void) {
	uint32_t count = 0;

	// Trigger pulse
	ULTRASONIC_PORT &= ~(1 << ULTRASONIC_TRIG_PIN);
	_delay_us(2);
	ULTRASONIC_PORT |= (1 << ULTRASONIC_TRIG_PIN);
	_delay_us(10);
	ULTRASONIC_PORT &= ~(1 << ULTRASONIC_TRIG_PIN);

	// Wait for ECHO pin to go high
	while (!(ULTRASONIC_PIN & (1 << ULTRASONIC_ECHO_PIN)));

	// Measure time while ECHO pin is high
	while (ULTRASONIC_PIN & (1 << ULTRASONIC_ECHO_PIN)) {
		count++;
		_delay_us(1);
	}

	return (count * 0.0343); // Calculate distance in cm
}


#endif // ULTRASONICSENSOR_H
