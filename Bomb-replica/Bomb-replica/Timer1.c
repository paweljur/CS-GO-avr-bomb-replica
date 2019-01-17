/*
 * Timer1.c
 *
 * Created: 13.01.2019 17:33:52
 *  Author: Pawe³ Jur
 */ 
#include "Timer1.h"

volatile int timerStartedFlag = 0;
volatile unsigned long interruptCounter = 0;
volatile int countDownStartedFlag = 0;
volatile unsigned long interruptsLeftToExplosion = InterruptsToExplode;
volatile int signalOnFlag = 0;
volatile int maxIntervalInterruptsCount = InterruptsPerInterval;
volatile int intervalInterruptsLeft = InterruptsPerInterval;
volatile int signalInterruptsLeft = InterruptsPerSignal;
volatile int interruptsToShortenIntervalLeft = InterruptsToShortenInterval;

ISR(TIMER1_OVF_vect){
	if(timerStartedFlag == 1) {
		interruptCounter++;
		if (countDownStartedFlag == 1) {
			interruptsLeftToExplosion--;
			interruptsToShortenIntervalLeft--;
			
			if(interruptsToShortenIntervalLeft <= 0) {
				maxIntervalInterruptsCount -= IntervalShortening;
				interruptsToShortenIntervalLeft = InterruptsToShortenInterval;
			}
			
			if(signalOnFlag == 1) {
				signalInterruptsLeft--;
				SignalOn();
				if(signalInterruptsLeft <= 0) {
					signalOnFlag = 0;
					intervalInterruptsLeft = maxIntervalInterruptsCount;
				}
			}
			else {
				intervalInterruptsLeft--;
				SignalOff();
				if(intervalInterruptsLeft <= 0) {
					signalOnFlag = 1;
					signalInterruptsLeft = InterruptsPerSignal;
				}
			}
			
			if(interruptsLeftToExplosion <= 0) {
				countDownStartedFlag = 0;
				SignalOff();
			}
		}
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
}

void TimerStop() {	
	timerStartedFlag = 0;
}

void StartCountdown() {
	countDownStartedFlag = 1;
}

void StopCountdown() {
	countDownStartedFlag = 0;
	SignalOff();
}

int IsCounting() {
	return countDownStartedFlag;
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

void SignalOn() {
	SpeakerOn();
	DiodeOn();
}

void SignalOff() {
	SpeakerOff();
	DiodeOff();
}

int GetInterruptsCount() {
	return interruptCounter;
}

void StartCountDown() {
	
}