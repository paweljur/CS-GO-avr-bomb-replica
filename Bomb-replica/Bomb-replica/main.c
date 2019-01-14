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

void InitialBeep() {
	SpeakerOn();
	_delay_ms(100);
	SpeakerOff();
	_delay_ms(75);
	SpeakerOn();
	_delay_ms(100);
	SpeakerOff();
}

void WriteCode(char code[7]) {
	for(int i = 0; i < 7; i++) {
		LCD_WriteData(code[i]);
	}
	LCD_Home();
}

void AddDigit(char *code, char digit, int size) {
	char tmp[7];
	strncpy(tmp, code, size);
	for(int i = 1 ; i < size; i++) {
		code[i - 1] = tmp[i];
	}
	code[size - 1] = digit;
}

void GetCode(char *code, const int size) {
	char pressed = NullKey;
	
	WriteCode(code);
	
	for(int i = 0; i < size; i++) {

		while(pressed == NullKey || pressed == KeyAsterisk || pressed == KeyHash) {
			pressed = GetKeyPressed();
		}
		
		DiodeOn();
		
		AddDigit(code, pressed, size);
		
		WriteCode(code);
		
		while(pressed != NullKey) {
			pressed = GetKeyPressed();
		}
	}
	
	while(pressed != KeyHash) {
		pressed = GetKeyPressed();
	}
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
	
	LCD_Clear();
	WriteCode(code);
	
	while(1){}
	
	return 0;
}

