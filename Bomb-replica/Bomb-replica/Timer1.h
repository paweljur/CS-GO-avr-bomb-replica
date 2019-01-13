/*
 * Timer1.h
 *
 * Created: 13.01.2019 17:34:03
 *  Author: Pawe³ Jur
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define Timeframe 9		//unit of time, equals to x interrupts
#define TimeframesPerSecond 400		//one timeframe equals to 0,0025s

void Timer1Init();
void TimerStart();
void TimerReset();
void TimerStop();

void SpeakerInit();
void SpeakerOn();
void SpeakerOff();

int GetSignalTimeInTimeframes();
void ResetSignalTime();

#endif /* TIMER1_H_ */