/*
 * Util.h
 *
 * Created: 14.01.2019 23:42:51
 *  Author: Pawe³ Jur
 */
#ifndef UTIL_H_
#define UTIL_H_

#include <avr/io.h>

void AddDigit(char *code, char digit, int size);
int Equal(char* first, char* second, int size);


#endif /* UTIL_H_ */