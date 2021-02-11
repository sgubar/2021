#include"dk_tool.h"

int main()
{
    int row, col;
    printf("Adding two matrices\n");
    printf("Number of columns in matrices:");
        scanf("%d", &col);
      printf("Number of rows in matrices:");
        scanf("%d", &row);

    int** m1 = create_matrix(row,col);
    int** m2 = create_matrix(row,col);

    put_rand_arr(m1,row,col);
    printf("\n");

    put_rand_arr(m2,row,col);
    printf("\n");

    printf("First matrix\n");
    print_matrix(m1,row,col);
    printf("\n");

    printf("Second matrix\n");
    print_matrix(m2,row,col);
    printf("\n");

    int** new_array = sum_matrix(m1,m2,row,col);
    printf("Sum\n");
    print_matrix(new_array,row,col);
    delete_matrix(new_array,  row);
}

