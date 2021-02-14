#include<stdio.h>
#include<stdlib.h>
#define DK_TOOL_H
#ifndef DK_TOOL_H

int **make_Matrix(int row, int col);
int fill_Matrix(int**	matrix, int row, int col);
void build_Matrix(int** matrix, int row, int col);
int** tr_Matrix(int** matrix, int row, int col);
void delete_Matrix(int** matrix, int row);



void out_matr(int** matrix, int row, int col);
#endif // !dk_tool.h
