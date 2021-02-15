#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "matrix.h"
//Отримуємо дані з клавіатури.
void getAWord(char* word,int size){
    fgets(word, size, stdin);
}
//Переводимо вводимі дані в числа.
int get_int(int size){
    char *buff = create_matrix_char(size);
    getAWord(buff,size);
    int result = atoi(buff);
    delete_matrix_char(buff);
    return result;
}
