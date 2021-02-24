#include <stdio.h>
#define dk_tool_H
#ifdef dk_tool_H

int** create_matrix(int row, int col);
void delete_matrix(int** matrix, int row);
void fill_matrix(int** matrix, int row, int col);
void print_matrix(int** matrix, int row, int col);
int** diff_matrix(int** matrix1, int** matrix2, int row, int col);
#endif
