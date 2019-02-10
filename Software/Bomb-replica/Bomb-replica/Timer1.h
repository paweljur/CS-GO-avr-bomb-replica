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
#include <stdio.h>
#include "NotificationDiode.h"
#include "HD44780.h"

#define InterruptsPerSecond 3600L
#define InterruptsToExplode 50 * InterruptsPerSecond
#define InterruptsToShortenInterval 125
#define IntervalShortening 2
#define InterruptsPerSignal 0.2 * InterruptsPerSecond
#define InterruptsPerInterval 0.8 * InterruptsPerSecond

void Timer1Init();
void TimerStart();
void TimerReset();
void TimerStop();

void StartCountdown();
void StopCountdown();
int IsCounting();

void SpeakerInit();
void SpeakerOn();
void SpeakerOff();
void SignalOn();
void SignalOff();

int GetInterruptsCount();
void ResetSignalTime();

#endif /* TIMER1_H_ */