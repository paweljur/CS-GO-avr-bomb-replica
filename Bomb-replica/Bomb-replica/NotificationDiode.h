/*
 * NotificationDiode.h
 *
 * Created: 13.01.2019 16:10:07
 *  Author: Pawe³ Jur
 */ 


#ifndef NOTIFICATIONDIODE_H_
#define NOTIFICATIONDIODE_H_

#include <avr/io.h>

#define DiodeDir	DDRD
#define DiodePort	PORTD
#define Diode		(1<<PD0)

void DiodeInit();
void DiodeOn();
void DiodeOff();


#endif /* NOTIFICATIONDIODE_H_ */