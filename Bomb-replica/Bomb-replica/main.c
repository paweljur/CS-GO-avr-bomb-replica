/*
 * Bomb-replica.c
 *
 * Created: 13.01.2019 15:15:57
 * Author : Pawel Jur
 */ 

#include <avr/io.h>
#include "NotificationDiode.h"
#include "Timer1.h"
#include "Keyboard.h"

int main(void)
{
	DiodeInit();
	KeyboardInit();
	
	while(1) {
		if(GetKeyPressed() != NullKey){
			DiodeOn();
		}
		else {
			DiodeOff();
		}
	}
	
	return 0;
}

