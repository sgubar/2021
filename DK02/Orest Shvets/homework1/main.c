#include"dk_tool.h"

int main()
{
    int row, col;
    printf("vvedit kilkist cols:");
    scanf_s("%d", &col);
    printf("vvedit kilkist rows:");
    scanf_s("%d", &row);

    int** m01 = create_matrix(row, col);
    int** m02 = create_matrix(row, col);

    random_arr(m01, row, col);
    random_arr(m02, row, col);
    

    print_matrix(m01, row, col);
    printf("\n");
    print_matrix(m02, row, col);
    printf("\n");
    int** rizn = rizn_matrix(m01, m02, row, col);
    print_matrix(rizn, row, col);
    delete_matrix(rizn, row);
}


