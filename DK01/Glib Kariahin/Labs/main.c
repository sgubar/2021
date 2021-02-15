#include <stdio.h>

#include "input_output.h"
#include "math.h"

int main() {

    //Вводимо дані
    printf("Hello. You entered into lab system. \n");
    printf("Please enter some data for operating... \n");
    printf("Enter number A : \n");
    int A = get_int(6);
    printf("Enter number B : \n");
    int B = get_int(6);
    printf("Enter number C : \n");
    int C = get_int(6);

    //!C==0
    //!(b+c^2)==0

    //Перевіряємо знаменник
    if((B+C*C)==0){
        printf("ERROR : WRONG DATA");
        return -1;
    }
    //Вивід результату
    printf("Result : ");
    printf("%f",q(A,B,C));
    return 0;
}
