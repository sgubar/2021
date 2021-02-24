#include<stdio.h>
#include<stdlib.h>
#pragma once
#define DK_TOOL_H
#ifdef DK_TOOL_H

//
int** transpMatrix(int** matrix, int row, int col);
int** create_matrix(int row, int col);
void delete_matrix(int** matrix, int row);
void put_rand_arr(int** matrix, int row, int col);
void out_matr(int** matrix, int row, int col);
#endif // 
