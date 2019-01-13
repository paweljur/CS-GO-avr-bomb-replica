/*
 * Timer1.c
 *
 * Created: 13.01.2019 17:33:52
 *  Author: Pawe³ Jur
 */ 
#include "Timer1.h"

volatile int timerStartedFlag = 0;
volatile int interruptCounter = 0;
volatile int signalTime = 0;

ISR(TIMER1_OVF_vect){
	if(timerStartedFlag == 1){
		if(interruptCounter >= Timeframe){
			signalTime++;
			interruptCounter = 0;
		}
		interruptCounter++;
	}
}

void Timer1Init() {
	
	//set fast pwm 8-bit ICR1
	TCCR1A |= (1<<WGM10);
	TCCR1B |= (1<<WGM12);
		
	//set prescaler /8
	TCCR1B |= (1<<CS11);
	
	//turn on timer
	TIMSK = (1<<TOIE1);
	
	//turn on interrupts
	sei();
}

void TimerStart() {
	timerStartedFlag = 1;
}

void TimerReset() {
	interruptCounter = 0;
	signalTime = 0;
}

void TimerStop() {	
	timerStartedFlag = 0;
}

void SpeakerInit() {
	//set timer to half
	OCR1A = 127;
	//set pin
	DDRB |= (1<<PB1);
}

void SpeakerOn() {
	TCCR1A |= (1<<COM1A1);
}

void SpeakerOff() {
	TCCR1A &=~ (1<<COM1A1);
}

int GetSignalTimeInTimeframes() {
	return signalTime;
}

void ResetSignalTime() {
	signalTime = 0;
}