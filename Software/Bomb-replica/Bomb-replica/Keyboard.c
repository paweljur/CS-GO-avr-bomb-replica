/*
 * Keyboard.c
 *
 * Created: 13.01.2019 22:16:14
 *  Author: Pawe³ Jur
 */ 
#include "Keyboard.h"

void KeyboardInit() {
	RowPort |= Row1;
	RowPort |= Row2;
	RowPort |= Row3;
	RowPort |= Row4;
	
	Column1Port |= Column1;
	Column1Dir |= Column1;
	Column2Port |= Column2;
	Column2Dir |= Column2;
	Column3Port |= Column3;
	Column3Dir |= Column3;
}

char CheckFirstColumn() {
	char letter = NullKey;
	Column1Port &=~ Column1;
	
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	
	int keys = Row & RowCheck;
	if(keys == Row1Enabled){
		letter = Key1;
	}
	else if(keys == Row2Enabled){
		letter = Key4;
	}
	else if(keys == Row3Enabled){
		letter = Key7;
	}
	else if(keys == Row4Enabled){
		letter = KeyAsterisk;
	}
	
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	
	Column1Port |= Column1;
	
	return letter;
}

char CheckSecondColumn() {
	char letter = NullKey;
	Column2Port &=~ Column2;
	
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	
	int keys = Row & RowCheck;
	if(keys == Row1Enabled){
		letter = Key2;
	}
	else if(keys == Row2Enabled){
		letter = Key5;
	}
	else if(keys == Row3Enabled){
		letter = Key8;
	}
	else if(keys == Row4Enabled){
		letter = Key0;
	}
	
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	
	Column2Port |= Column2;
	
	return letter;
}

char CheckThirdColumn() {
	char letter = NullKey;
	Column3Port &=~ Column3;
	
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	
	int keys = Row & RowCheck;
	if(keys == Row1Enabled){
		letter = Key3;
	}
	else if(keys == Row2Enabled){
		letter = Key6;
	}
	else if(keys == Row3Enabled){
		letter = Key9;
	}
	else if(keys == Row4Enabled){
		letter = KeyHash;
	}
	
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	
	Column3Port |= Column3;
	
	return letter;
}

char GetKeyPressed() {
	char letter = CheckFirstColumn();
	if(letter == NullKey){
		letter = CheckSecondColumn();
		if(letter == NullKey){
			letter = CheckThirdColumn();
		}
	}
	return letter;
}