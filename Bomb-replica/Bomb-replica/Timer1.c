/*
 * Timer1.c
 *
 * Created: 13.01.2019 17:33:52
 *  Author: Pawe³ Jur
 */ 
#include "Timer1.h"

volatile int timerStartedFlag = 0;
volatile int interruptCounter = 0;
volatile int timeSinceStart = 0;

ISR(TIMER1_OVF_vect){
	if(timerStartedFlag == 1){
		if(interruptCounter >= Timeframe){
			timeSinceStart++;
			interruptCounter = 0;
		}
		interruptCounter++;
	}
}

void Timer1Init() {
	
	//set fast pwm ICR1
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
	timeSinceStart = 0;
}

void TimerStop() {	
	timerStartedFlag = 0;
}

double GetTimeSinceStartInSec() {
	return timeSinceStart / TimeframesPerSecond;
}

int GetTimeSinceStartInTimeframes() {
	return timeSinceStart;
}