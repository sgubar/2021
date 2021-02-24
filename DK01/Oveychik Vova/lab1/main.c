#include <stdio.h>
#include <stdlib.h>
#include "funk_math.h"

int main()
{   int a,b,c;
    printf("Hello world!\n Write please number A,B,C\n");
    scanf("%d\n%d\n%d",&a,&b,&c);

    printf("square %d = %ld\n",a,kvad(a));
    printf("square %d = %ld\n",b,kvad(b));
    printf("factorial %d = %ld\n",b,fakt(b));
    printf("number 5 in step %d =%f\n",c,in_step(c));/* ці рядки коду можна закоментувати
                                                        або видалити призначені для перевірки програми*/
    printf("result of calculation=%f",res(a,b,c));
    return 0;
}
