/*
 * Keyboard.h
 *
 * Created: 13.01.2019 22:16:28
 *  Author: pawel
 */ 


#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <avr/io.h>
#include "NotificationDiode.h"

#define NullKey		' '
#define Key1		'1'
#define Key2		'2'
#define Key3		'3'
#define Key4		'4'
#define Key5		'5'
#define Key6		'6'
#define Key7		'7'
#define Key8		'8'
#define Key9		'9'
#define Key0		'0'
#define KeyAsterisk '*'
#define KeyHash		'#'

#define RowPort			PORTC
#define Row				PINC
#define RowCheck		0b00101011
#define Row1			(1<<PC5)
#define Row1Enabled		0b00001011
#define Row2			(1<<PC0)
#define Row2Enabled		0b00101010
#define Row3			(1<<PC1)
#define Row3Enabled		0b00101001
#define Row4			(1<<PC3)
#define Row4Enabled		0b00100011

#define Column1Port PORTC
#define Column1Dir DDRC
#define Column1	(1<<PC4)

#define Column2Port PORTB
#define Column2Dir DDRB
#define Column2	(1<<PB2)

#define Column3Port PORTC
#define Column3Dir DDRC
#define Column3	(1<<PC2)

void KeyboardInit();
char GetKeyPressed();


#endif /* KEYBOARD_H_ */