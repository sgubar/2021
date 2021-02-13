#include "My_MATH.h"

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int A = -1, B = -1, C = -1;

    printf("Введите целые положительные числа до 12!\n");

    do
    {
        printf("А: ");
        scanf_s("%d", &A);
        printf("B: ");
        scanf_s("%d", &B);
        printf("С: ");
        scanf_s("%d", &C);
        if ((A < 0) || (B < 0) || (C < 0) || (A > 12) || (B > 12) || (C > 12))
            printf("Введите нормальные значения\n");

    } while ((A < 0) || (B < 0) || (C < 0) || (A > 12) || (B > 12) || (C > 12));    

    printf ("Ответ: %f\n", formula(A, B, C));

    system("pause");
    return 0;
}
