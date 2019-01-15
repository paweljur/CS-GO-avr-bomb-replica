/*
 * Util.c
 *
 * Created: 14.01.2019 23:42:39
 *  Author: Pawe³ Jur
 */ 
#include "Util.h"



void AddDigit(char *code, char digit, int size) {
	char tmp[7];
	strncpy(tmp, code, size);
	for(int i = 1 ; i < size; i++) {
		code[i - 1] = tmp[i];
	}
	code[size - 1] = digit;
}

int Equal(char* first, char* second, int size) {
	for(int i = 0; i < size; i ++) {
		if(first[i] != second[i]) {
			return 0;
		}
	}
	return 1;
}