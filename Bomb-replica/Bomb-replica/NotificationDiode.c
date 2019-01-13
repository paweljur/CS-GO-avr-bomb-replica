/*
 * NotificationDiode.c
 *
 * Created: 13.01.2019 16:09:49
 *  Author: Pawe³ Jur
 */ 
#include "NotificationDiode.h"

void DiodeInit() {
	DiodeDir |= Diode;
}

void DiodeOn() {
	DiodePort |= Diode;
}

void DiodeOff(){
	DiodePort &=~ Diode;
}