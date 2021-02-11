#include "dk_tool.h"


int**  getMatrix(int row, int col) {
    int i=0, j=0;
    int **arr = (int **)malloc(sizeof(int *) * row);//виділяємо пам'ять

    for(i = 0; i < row; i++) {
        arr[i] = (int *)malloc(sizeof(int *) * col);
    }

    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {

          arr[i][j] = rand() % 100;//забиваємо числами від 0 до 99

        /*printf("Elements of matrix [%d][%d]: ", i, j);//можна погратися з вводом
        scanf("%d", &arr[i][j]);*/
        }
    }
        return arr;
}
int **sumMatr(int **arr1, int **arr2, int row, int col) {//функція суми
    int i, j;
    
    for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                arr1[i][j] += arr2[i][j];//переписуємо результат в першу матрицю
            }
        }
        delete_matrix(arr2, row);//чистимо матрицю
    return arr1;
}
void delete_matrix(int **arr, int row) {//чистка матриці
	if (arr == NULL) {
		return;
    }
    for (int i = 0; i < row; i++) {
		free (arr[i]); }
    free(arr);
}

void printMatrix(int **resarr, int row, int col) {//виводимо матрицю
    int i, j;
    for(i = 0; i < row; i++) { 
        for(j = 0; j < col; j++) {
            printf("%4d", resarr[i][j]);
        }
        printf("\n");
    }
}
