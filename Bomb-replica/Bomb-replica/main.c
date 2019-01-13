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
	SpeakerInit();
	
	TimerStart();
	
	while(1) {
		if(GetSignalTimeInTimeframes() < TimeframesPerSecond) {
			DiodeOn();
			SpeakerOn();
		}
		else if (GetSignalTimeInTimeframes() < (TimeframesPerSecond * 2))  {
			DiodeOff();
			SpeakerOff();
		}
		else {
			ResetSignalTime();
		}
		
	}
	
	return 0;
}

