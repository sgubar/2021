#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"
#include <stdbool.h>
#include <errno.h>

// Error codes
const int DOESNT_EXIST = -1;
const int NULLPASS = -2;
const int COLROW_ERR = -3;
const int NOT_A_TYPE = -4;
const int OVERSIZED = -5;
const int NOT_A_HEX = -6;
const int NOT_OCT = -7;
const int NOT_A_BIN = -8;
const int MATR_MULT_ERR = -9;

const int OK = 0;

int ** create_matrix(int rows, int columns) { // створює матрицю
	if(columns <= 0 || rows <= 0) {
		errno = COLROW_ERR;
		return NULL;
	}

	int **matrix = (int **) malloc(sizeof(int **) * rows);

	for(int i = 0; i < rows; i++) {
		*(matrix + i) = (int *) malloc(sizeof(int) * columns);
	}

	return matrix;
}

int delete_matrix(int **matrix, int rows) { // видаляє матрицю з пам'яті
	if(matrix == NULL)
		return NULLPASS;

	for(int i = 0; i < rows; i++) {
		free(*(matrix + i));
	}

	return OK;
}

int ** sum_sub_matrixes(int **matrix1, int **matrix2, int rows, int columns) { // сумує та віднімає матриці
	if(matrix1 == NULL || matrix2 == NULL) {
		errno = NULLPASSED;
		return NULL;
	}

	if(rows <= 0 || columns <= 0) {
		errno = COLROW_ERR;
		return NULL;
	}

	int **result = create_matrix(rows, columns);

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			*(result + i * columns + j) = matrix1[i][j] + matrix2[i][j];

	return result;
}

int ** mult_matrixes(int **matrix1, int **matrix2, int r1, int c1, int r2, int c2) {
	if(c1 != r2) {
		errno = MATRIX_MULT_ERR;
		return NULL;
	}

	int **result = create_matrix(r1, c2);

	for(int i = 0; i < r1; i++) {
		for(int j = 0; j < c2; j++) {
			int res = 0;

			for(int r = 0; r < c1; r++)
				res += matrix1[i][r] * matrix2[r][j];

			*(result + i * c2 + j) = res;
		}
	}

	return result;
}

int get_chrs_pos(char *charset, char *string, int chrs_buff_size, int str_buff_size) { // повертає позицію першого входження строки
	if(string == NULL)
		return NULLPASS;

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

	if(array == NULL)
		return NULLPASS;

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
	if(string == NULL)
		return NULLPASS;

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
	if(num == NULL)
		return NULLPASS;

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




