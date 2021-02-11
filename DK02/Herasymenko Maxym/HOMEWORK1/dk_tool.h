#include <stdio.h>
#define dk_tool_H
#ifdef dk_tool_H

int** create_matrix(int row, int col);
void delete_matrix(int** matrix, int row);
void put_rand_arr(int** matrix, int row, int col);
void print_matrix(int** matrix, int row, int col);
int** sum_matrix(int** matrix1, int** matrix2, int row, int col);
#endif
