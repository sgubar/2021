#include"dk_tool.h"

int main()
{
    int row =0;
    int col = 0;
    
    do
    {
    printf("Number of columns in matrices:");
    scanf("%d", &col);
    printf("Number of rows in matrices:");
    scanf("%d", &row);
    } while(col<2 && row<2);

    int** m1 = create_matrix(row,col);
    int** m2 = create_matrix(row,col);

    fill_matrix(m1,row,col);
    printf("\n");

    fill_matrix(m2,row,col);
    printf("\n");

    printf("First matrix\n");
    print_matrix(m1,row,col);
    printf("\n");

    printf("Second matrix\n");
    print_matrix(m2,row,col);
    printf("\n");

    int** new_matrix = diff_matrix(m1,m2,row,col);
    printf("diff\n");
    print_matrix(new_matrix,row,col);
    delete_matrix(new_matrix,  row);
}
