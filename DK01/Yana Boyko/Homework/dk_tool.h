#ifndef _DK_TOOL_H
#define _DK_TOOL_H

#include <stdio.h> 
#include <stdlib.h>
int** create_array(int rows, int cols);
void array_up(int** array, int rows, int cols, int num_up);
void delete_array(int** array, int rows);
void print_array(int** array, int rows, int cols);
void fill_array(int** array, int rows, int cols);

#endif
