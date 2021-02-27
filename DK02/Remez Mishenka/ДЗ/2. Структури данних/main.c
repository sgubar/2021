#include <stdio.h>
#include <Windows.h>
#include "Figures.h"

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Dot* A = input_dot();
    Dot* B = input_dot();
    Dot* C = input_dot();
    Dot* D = input_dot();

    Square* Slozhna = make_square(A, B, C, D);
    figures* arr_squares = make_many_squares(1);
    set_square_by_index(arr_squares, Slozhna, 10);

    if (check_square(get_square_dy_index(arr_squares, 10)))
    {
        print_square(get_square_dy_index(arr_squares, 10));
    }
    else
        printf("\nПлохой человек введи нормальные координаты вершин квадрата\n");

    delete_square(Slozhna);
    delete_figures(arr_squares);

    system("pause");
}