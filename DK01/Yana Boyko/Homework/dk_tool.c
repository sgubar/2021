#include "dk_tool.h"

void array_up(int** array, int rows, int cols, int num_up) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] *=  num_up;
        }
    }
}

void print_array(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void fill_array(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % 10;
        }
    }
}

int** create_array(int rows, int cols) {
    int** array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
         array[i] = (int *)malloc(cols * sizeof(int));
    return array;
}

void delete_array(int** array, int rows) {
    if (array != NULL) {
        for (int i = 0; i < rows; i++){
            free(array[i]);
        }
        free(array);
    }
}
