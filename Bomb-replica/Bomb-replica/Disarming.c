/*
 * Disarming.c
 *
 * Created: 14.01.2019 22:42:11
 *  Author: Pawe³ Jur
 */ 
#include "Disarming.h"

int firstKeyPress = 1;
int keyWasReleased = 1;
char currentCode[DisarmCodeSize];
int currentCodeLength = 0;
char actualCode[DisarmCodeSize];

void DisarmingInit(char * code) {
	memset(currentCode, KeyAsterisk, DisarmCodeSize);
	strncpy(actualCode, code, DisarmCodeSize);
}

void IfDigitAddToCode(char pressedKey) {
	if(pressedKey != NullKey && pressedKey != KeyAsterisk && pressedKey != KeyHash) {
		AddDigit(currentCode, pressedKey, DisarmCodeSize);
		currentCodeLength++;
		WriteCode(currentCode);
	}
}


int IsDisarmed() {
	int result = NotDisarmed;
	
	char pressedKey = GetKeyPressed();
	
	if(pressedKey != NullKey && keyWasReleased == 1){
		keyWasReleased = 0;
		
		if(firstKeyPress == 1){
			firstKeyPress = 0;
			WriteCode(currentCode);
			
			IfDigitAddToCode(pressedKey);
		}
		else {
			if(currentCodeLength < DisarmCodeSize) {
				IfDigitAddToCode(pressedKey);
			} 
			else if(pressedKey == KeyHash) {
				
				if (Equal(actualCode, currentCode, DisarmCodeSize) == 0) {
					LCD_WriteText("Detonated");
					result = Detonated;
				}
				else {
					LCD_WriteText("Disarmed");
					result = Disarmed;
				}
			}
		}
		
	} else if (pressedKey == NullKey) {
		keyWasReleased = 1;
	}
	
	return result;
}