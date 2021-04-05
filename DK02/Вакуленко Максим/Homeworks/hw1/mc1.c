// FirstPrg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include"dk_tool.h"
int main() {
    int num_up, row, col;// число для множення матриці
    printf("Type a high of arrey:");
        scanf_s("%d", &row);
    printf("\nType a long of arrey: ");
        scanf_s("%d", &col);
    
    int* one_line_arrey = create_matrix1(row, col);
    feel_arrey(one_line_arrey, row, col);
    print_matr(one_line_arrey, row, col);
    printf("Random arrey generated\n Enter num for multiplication: "); 
    scanf_s("%d", &num_up); 
    arrey_up(one_line_arrey, row, col, num_up);
    print_matr(one_line_arrey, row, col);
    delete_matrix1(one_line_arrey);
    one_line_arrey = NULL;



}
