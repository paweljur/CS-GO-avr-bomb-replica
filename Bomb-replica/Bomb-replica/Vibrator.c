/*
 * Vibrator.c
 *
 * Created: 19.01.2019 11:50:08
 *  Author: Pawe³ Jur
 */ 
#include "Vibrator.h"

void VibratorInit() {
	//fast PWM
	TCCR2 |= (1<<WGM20) | (1<<WGM21);
	//prescaler 64 -> 450hz PWM
	TCCR2 |= (1<<CS22);
	//impuls width
	OCR2 = 200;
	
	VibratorDir |= Vibrator;
}

void VibratorOn() {
	TCCR2 |= (1<<COM21);
}

void VibratorOff() {
	TCCR2 &=~ (1<<COM21);
}