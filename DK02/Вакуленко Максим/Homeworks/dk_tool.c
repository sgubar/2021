#include"dk_tool.h"
void arrey_up(int* matrix, int row, int col, int num_up) {
    for (int b = 0; b < row; b++) {
        for (int i = 0; i < col; i++) {
            *(matrix + i + b * col) *= num_up;
        }
    }
}

void print_matr(int* matrix, int row, int col) {

    for (int b = 0; b < row; b++) {
        for (int i = 0; i < col; i++) {
            printf(" %d ", *(matrix + i + b * col));
        }
        printf("\n");
    }
}

void feel_arrey(int* matrix, int row, int col) {
    for (int i = 0; i < row * col; i++) {
        *(matrix + i) = rand() % 10;
    }
}

int* create_matrix1(int row, int col) {
    return (int*)malloc(sizeof(int) * row * col);
}
void delete_matrix1(int* matrix) {
    if (matrix != NULL) {
        free(matrix);
    }
}
