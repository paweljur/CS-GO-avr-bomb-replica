/*
 * Bomb-replica.c
 *
 * Created: 13.01.2019 15:15:57
 * Author : Pawel Jur
 */ 

#include <avr/io.h>
#include "NotificationDiode.h"
#include "Timer1.h"

int main(void)
{
	DiodeInit();
	
	Timer1Init();
	TimerStart();
	
	while(1) {
		if((GetTimeSinceStartInTimeframes() % (TimeframesPerSecond * 2)) < TimeframesPerSecond) {
			DiodeOn();
		}
		else  {
			DiodeOff();
		}
		
	}
	
	return 0;
}

