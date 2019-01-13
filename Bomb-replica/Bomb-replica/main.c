/*
 * Bomb-replica.c
 *
 * Created: 13.01.2019 15:15:57
 * Author : Pawel Jur
 */ 

#include <avr/io.h>
#include "NotificationDiode.h"


int main(void)
{
	DiodeInit();
	DiodeOn();
	
	while(1) {
		
	}
	
	return 0;
}

