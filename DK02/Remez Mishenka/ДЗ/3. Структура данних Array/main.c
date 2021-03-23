#include <Windows.h>
#include "Figures.h"

#define size_arr 2

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	figures* my_array = make_many_squares(1);

	for (int i = 0; i < size_arr; i++)
	{
		printf("\n¬ведите квадрат %d\n", i + 1);
		Square* sq = make_square(input_dot(), input_dot(), input_dot(), input_dot());
		if (check_square(sq))
			set_square_by_index(my_array, sq, i);
		else
		{
			i--;
			printf("\n!!! ¬ведены неверные точки !!!\n");
		}			
	}
	print_arr_by_sq(my_array, 1);	//0 - детальные параметры квадрата, 1 и более - упрощенные параметры (только координаты)

	printf("ѕлощадь всех квадратов: %.01f\n", count_s(my_array));

	delete_figures(my_array);
	system("pause");
	return 0;
}