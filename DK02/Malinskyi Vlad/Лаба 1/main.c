#include <stdio.h>
#include <stdlib.h>

#include "myPow.h"
#include "mySquare.h"
#include "myFactorial.h"


int main()
{

    double a, b, c;


    double chiselnik, znamennik, bFac;

    double numToPow, answer;
    numToPow = 5.0;

    printf("Enter a\n");
    scanf("%f", &a);
    printf("Enter b\n");
    scanf("%f", &b);
    printf("Enter c (b + 5^c mustn't equal 0)\n");
    scanf("%f", &c);


    chiselnik = mySquare(a) + mySquare(b);
    znamennik = b + myPow(c, numToPow);
    bFac = fac(b);

    answer = (chiselnik/znamennik) + bFac;
    printf("Your desired answer: %lf", answer);


    return 0;
}
