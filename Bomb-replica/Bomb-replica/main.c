/*
 * Bomb-replica.c
 *
 * Created: 13.01.2019 15:15:57
 * Author : Pawel Jur
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <string.h>

#include "Timer1.h"
#include "Keyboard.h"
#include "HD44780.h"
#include "NotificationDiode.h"
#include "Disarming.h"
#include "Util.h"

void InitialBeep() {
	SpeakerOn();
	_delay_ms(100);
	SpeakerOff();
	_delay_ms(75);
	SpeakerOn();
	_delay_ms(100);
	SpeakerOff();
}



void GetCode(char *code, const int size) {
	char pressed = NullKey;
	
	WriteCode(code);
	
	for(int i = 0; i < size; i++) {

		while(pressed == NullKey || pressed == KeyAsterisk || pressed == KeyHash) {
			pressed = GetKeyPressed();
		}
		
		AddDigit(code, pressed, size);
		
		WriteCode(code);
		
		while(pressed != NullKey) {
			pressed = GetKeyPressed();
		}
	}
	
	while(pressed != KeyHash) {
		pressed = GetKeyPressed();
	}
	
	while(pressed != NullKey) {
		pressed = GetKeyPressed();
	}
	
	LCD_Clear();
	LCD_Home();
}

int main(void)
{
	Timer1Init();
	SpeakerInit();
	KeyboardInit();
	DiodeInit();
	LCD_Initalize();
	
	TimerStart();
	LCD_Clear();
	LCD_Home();
	
	InitialBeep();
	
	const int codeSize = 7;
	
	char code[codeSize];
	memset(code, KeyAsterisk, codeSize);
	GetCode(code, codeSize);
	
	DisarmingInit(code);
	StartCountdown();
	
	int isDisarmed = NotDisarmed;
	while(isDisarmed == NotDisarmed){
		isDisarmed = IsDisarmed();
		if(IsCounting() == 0){
			isDisarmed = Detonated;
		}
	}
	
	StopCountdown();
	LCD_Clear();
	if(isDisarmed == Disarmed) {
		LCD_WriteText("Disarmed");
	}
	else {	
		LCD_WriteText("KABOOM");
		while (1) {
			DiodeOff();
			_delay_ms(50);
			DiodeOn();
			_delay_ms(50);
		}
	}
	
	return 0;
}

