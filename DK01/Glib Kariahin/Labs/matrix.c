//
// Created by 123 on 15.02.2021.
//
#include <stdio.h>
#include <stdlib.h>

//Створюємо матриці для запису даних
char *create_matrix_char(int row) {
    return (char *)malloc(row);
}
//Видаляємо створену матрицю
void delete_matrix_char(char *matrix) {
    if (matrix != NULL) {
        free(matrix);
    }
}
