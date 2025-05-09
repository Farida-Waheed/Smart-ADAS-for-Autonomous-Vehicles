
#ifndef BUZZER_H
#define BUZZER_H

#include <avr/io.h>

// Define pin for Buzzer
#define BUZZER_PIN    PB6
#define BUZZER_PORT   PORTB
#define BUZZER_DDR    DDRB

// Function prototypes and implementations

void Buzzer_Init(void) {
	BUZZER_DDR |= (1 << BUZZER_PIN); // Set buzzer pin as output
}

void Buzzer_On(void) {
	BUZZER_PORT |= (1 << BUZZER_PIN); // Set buzzer pin high
}

void Buzzer_Off(void) {
	BUZZER_PORT &= ~(1 << BUZZER_PIN); // Set buzzer pin low
}

#endif // BUZZER_H
