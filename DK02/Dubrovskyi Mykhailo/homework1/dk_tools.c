#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"
#include <stdbool.h>
#include <errno.h>

// Error codes
const int DOESNT_EXIST = -1;
const int NOT_A_TYPE = -2;
const int OVERSIZED = -3;
const int NOT_A_HEX = -4;
const int NOT_OCT = -5;
const int NOT_A_BIN = -6;

const int OK = 0;

// to do: matrixes

int get_chrs_pos(char *charset, char *string, int chrs_buff_size, int str_buff_size) { // повертає позицію першого входження строки
	char *cstr = (char *) malloc(chrs_buff_size + 1);
	*(cstr + chrs_buff_size) = '\0';

	int max = str_buff_size - (chrs_buff_size - 1);
	
	for(int i = 0; i < max; i++) {
		for(int j = 0; j < chrs_buff_size; j++) {
			*(cstr + j) = *(string + i + j);
		}

		if(!strcmp(charset, cstr))
			return i;

	}

	return DOESNT_EXIST;
}

void * cparray(void *array, int size, enum Type t) { // копіює масив типу int/char/long ( потрібна для функції rearrange() )
	void *copy = (t == Int) ? (int *) malloc(sizeof(int) * size) : ( (t == Char) ? (char *) malloc(sizeof(char) * size) : (long *) malloc(sizeof(long)) );	

	for(int i = 0; i < size; i++) {
		if(t == Int)
			*((int *)copy + i) = *((int *)array + i);

		else if(t == Char)
			*((char *)copy + i) = *((char *)array + i);

		else if(t == Long)
			*((long *)copy + i) = *((long *)array + i);

	}

	return copy;
}

int rearrange(void *array, int size, enum Type t) { // міняє місцями елементи масиву
	if(t < Int || t > Long)
		return NOT_A_TYPE;

	void *copy = cparray(array, size, t);
	
	for(int i = 0; i < size; i++) {
		if(t == Int) {
			if(i >= size / 2)
				*((int *)array + size - (i + 1)) = *((int *)copy + i);
			else
				*((int *)array + size - (i + 1)) = *((int *)array + i);

		} else if(t == Char) {
			if(i >= size / 2)
				*((char *)array + size - (i + 1)) = *((char *)copy + i);
			else
				*((char *)array + size - (i + 1)) = *((char *)array + i);

		} else if(t == Long) {
			if(i >= size / 2)
				*((long *)array + size - (i + 1)) = *((long *)copy + i);
			else
				*((long *)array + size - (i + 1)) = *((long *)array + i);
		}

	}

	free(copy);

	return OK;
}

int count_words(char *string, int str_buff_size) { // рахує кількість слів у реченні
	int word_amount = 0;
	_Bool is_out = true;
	
	for(int i = 0; i < str_buff_size; i++) {
		if( *(string + i) != ' ' && *(string + i) != ',' && *(string + i) != '?' && *(string + i) != '!' && *(string + i) != '.' && is_out) {
			is_out = false;

		} else if( *(string + i) == '.' || *(string + i) == '?' || *(string + i) == '!' && !is_out ) {
			word_amount++;
			break;
		
		} else if(!is_out) {
			is_out = true;
			word_amount++;
		}

	}

	return word_amount;
}

int base16_to_base10(char *num) { // переводить з шістнадцяткової системи числення у десятичну
	int size = strlen(num);

	if(size > 4)
		return OVERSIZED;

	int result = 0;

	for(int i = 0; i < size; i++) {
		if(num[i] >= '0' && num[i] <= '9') {
			result += ((int) num[i] - '0') * pow(16, size - (i + 1));
			continue;
		}

		switch(num[i]) {
			case 'a':
				result += 10 * pow(16, size - (i + 1));
				break;

			case 'b':
				result += 11 * pow(16, size - (i + 1));
				break;

			case 'c':
				result += 12 * pow(16, size - (i + 1));
				break;

			case 'd':
				result += 13 * pow(16, size - (i + 1));
				break;

			case 'e':
				result += 14 * pow(16, size - (i + 1));
				break;

			case 'f':
				result += 15 * pow(16, size - (i + 1));
				break;

			default:
				return NOT_A_HEX;
		}

	}

	return result;
}




