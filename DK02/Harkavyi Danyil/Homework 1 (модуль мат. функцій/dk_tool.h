#pragma once
#include <stdio.h>
#include <stdlib.h>
#define DK_TOOL_H
#ifdef DK_TOOL_H

int** make_matr(int row, int col);
void put_random(int** matr1, int row, int col);
void vivod_matr(int** matr1, int row, int col);
int** mno_matr(int** matr2, int** matr1, int row, int col);
void delete_matrix(int** matrix, int row);

#endif // DK_TOOL_H