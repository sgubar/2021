#include"dk_tool.h"
int** create_matrix(int row, int col)
{
    int** matrix = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++)
    {
        *(matrix + i) = (int*)malloc(sizeof(int) * col);
    }
    return matrix;
}

void delete_matrix(int** matrix, int row)
{
    if (matrix == NULL)
    {
        return;
    }
    for (int i = 0; i < row; i++)
    {
        free(*(matrix + i));
    }
    free(matrix);
}

void put_rand_arr(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)

        {
         *(*(matrix + i) + j) = rand() % 100;
        }
    }
}

void print_matrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
     for (int j = 0; j < col; j++)
     {
         printf("%d ", *(*(matrix + i) + j));
     }
     printf("\n");
    }
}

int** sum_matrix(int** matrix1, int** matrix2, int row, int col)
{
    int** new_array = create_matrix(row,col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(*(new_array + i) + j) = *(*(matrix1 + i) + j) + *(*(matrix2 + i) + j);
        }
    }
    return new_array;
}


int** sum_matr(int** matrix1, int** matrix2, int row, int col)
{
    int** new_array = create_matrix(row,col);
    for (int i = 0; i <row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(*(new_array + i) + j) = *(*(matrix1 + i)+ j) + *(*(matrix2 + i) + j);
        }
    }
    return new_array;
}
