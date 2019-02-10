/*
 * Vibrator.h
 *
 * Created: 19.01.2019 11:50:22
 *  Author: Pawe³ Jur
 */ 


#ifndef VIBRATOR_H_
#define VIBRATOR_H_

#include <avr/io.h>

#define VibratorPort PORTB
#define VibratorDir DDRB
#define Vibrator (1<<PB3)

void VibratorInit();
void VibratorOn();
void VibratorOff();


#endif /* VIBRATOR_H_ */