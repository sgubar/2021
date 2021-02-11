#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"
#include <stdbool.h>

// Error codes
const int NAT_NO = 1;

// Error messages
const char NAT_MESS[] = "Error: unknown type has been passed to a function\n";

void check_type(enum Type t) {
	if(t < Int || t > Long) {
		fputs(NAT_MESS, stderr);
		exit(EXIT_FAILURE);
	}
}

// to do: matrixes

int get_chrs_pos(char *charset, char *string, int chrs_buff_size, int str_buff_size) {
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

	return -1;
}

void * cparray(void *array, int size, enum Type t) {
	void *copy;
	copy = (t == Int) ? (int *) malloc(sizeof(int) * size) : ( (t == Char) ? (char *) malloc(sizeof(char) * size) : (long *) malloc(sizeof(long)) );	

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

void * rearrange(void *array, int size, enum Type t) {
	check_type(t);
	void *copy = cparray(array, size, t);
	
	for(int i = 0; i < size; i++) {
		if(t == Int) {
			if(i >= size / 2)
				*((int *)array + size - (i + 1)) =  *((int *)copy + i);
			else
				*((int *)array + size - (i + 1)) =  *((int *)array + i);

		} else if(t == Char) {
			if(i >= size / 2)
				*((char *)array + size - (i + 1)) =  *((char *)copy + i);
			else
				*((char *)array + size - (i + 1)) =  *((char *)array + i);

		} else if(t == Long) {
			if(i >= size / 2)
				*((long *)array + size - (i + 1)) =  *((long *)copy + i);
			else
				*((long *)array + size - (i + 1)) =  *((long *)array + i);
		}
	}

	return array;
}


