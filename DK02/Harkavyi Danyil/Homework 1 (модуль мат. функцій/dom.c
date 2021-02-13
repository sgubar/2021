
#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(){
    int** matrix1 = make_matr(4, 4);
    int** matrix2 = make_matr(4, 4);
    put_random(matrix1, 4, 4);
    put_random(matrix2, 4, 4);
    vivod_matr(matrix1, 4, 4);
    printf("\n");
    vivod_matr(matrix2, 4, 4);
    printf("\n");
    int** mnomatr = mno_matr(matrix2,matrix1, 4, 4);
    vivod_matr(mnomatr, 4, 4);

}

















