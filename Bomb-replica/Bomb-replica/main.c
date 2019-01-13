/*
 * Bomb-replica.c
 *
 * Created: 13.01.2019 15:15:57
 * Author : Pawel Jur
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include "NotificationDiode.h"
#include "Timer1.h"
#include "Keyboard.h"
#include "HD44780.h"

int main(void)
{
	int reset = 0;
	KeyboardInit();
	LCD_Initalize();
	LCD_Clear();
	LCD_Home();
	
	while(1) {
		char letter = GetKeyPressed();
		char* message = malloc(sizeof(letter));
		message[0] = letter;
		if(letter != NullKey && reset == 0){
			LCD_WriteText(message);
			reset = 1;
		}
		else if(letter == NullKey && reset == 1) {
			LCD_Clear();
			reset = 0;
		}
	}
	
	return 0;
}

