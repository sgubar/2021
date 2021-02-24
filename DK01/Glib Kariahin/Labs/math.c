//
// Created by 123 on 09.02.2021.
//
#include "math.h"
#include <stdio.h>
#define MOD(n) (n < 0 ? -n : n) // (condition) ? <> : <>

//Метод піднесення степеня. Додано умову що 0^0 не існує.
double power(int base, int pow) {

    //! 0^0 не існує
    if(base==0&&pow==0){
        printf("ERROR : WRONG DATA");
        return -1;
    }
    double result = 1;
    int pw = MOD(pow);

    for (int i = 0; i < pw; i ++) {
        result *= base;
    }

    return (pow < 0) ? 1.0 / result : result;
}


long factorial(int number) {
    long result = 1;


    if (number < 0) {
        printf("ERROR : WRONG DATA");
        return -1;
    }
    if(number == 0){
        return 1;
    }

    for (int i = 1; i <= number; i ++) {
        result *= i;
    }

    return result;
}

long sum_factor(int start, int finish) {
    long result = 0;

    for (int i = start; i < finish; i ++) {
        result += factorial(i + finish);
    }

    return result;
}


double q(int A, int B, int C) {
    return (A * B / (double)(B + power(C, 2))) + (double)sum_factor(0, B);
}