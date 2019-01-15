/*
 * Disarming.h
 *
 * Created: 14.01.2019 22:42:24
 *  Author: Pawe³ Jur
 */ 
#ifndef DISARMING_H_
#define DISARMING_H_

#include <avr/io.h>
#include <string.h>

#include "Keyboard.h"
#include "NotificationDiode.h"
#include "HD44780.h"
#include "Util.h"

#define NotDisarmed 0
#define Disarmed 1
#define Detonated 2
#define DisarmCodeSize 7

void DisarmingInit(char* actualCode);
int IsDisarmed();


#endif /* DISARMING_H_ */