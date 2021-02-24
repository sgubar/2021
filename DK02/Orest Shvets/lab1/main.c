


#include "math.h"
#define MOD(n) (n < 0 ? -n : n)


int main()
{
    int A, B, C;
    printf("vvedit chuslo A: ");
    scanf("%d", &A);
    printf("vvedit chuslo B: ");
    scanf("%d", &B);
    printf("vvedit chuslo C: ");
    scanf("%d", &C);
    while (A <= 0)
    {
        printf("A <= D, vvedit chuslo bilshe za 0: ");
        scanf("%d", A);
    }
    while (100 - B - C == 0)
    {
        printf("100-B-C = 0\n");
        printf("vvedit chuslo B: ");
        scanf("%d", B);
        printf("vvedit chuslo C: ");
        scanf("%d", C);
    }
    Q(A, B, C);
    printf("%f", Q(A, B, C));
    return 0;


}







