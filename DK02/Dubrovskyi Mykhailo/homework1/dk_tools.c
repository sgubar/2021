#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"

// to do: matrixes

int get_chrs_pos(char *charset, char *string, int chrs_buff_size, int str_buff_size) {
	char *cstr = (char *) malloc(chrs_buff_size + 1);
	*(cstr + chrs_buff_size + 1) = '\0';

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


