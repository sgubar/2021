#include <stdio.h>
#ifdef math_h
#define math_h 


#define math.h
double power(int base, int pow);
long factorial(int base);
double q(int A, int B, int C) {
    int sigma = 0;
    for (int D = 0; D <= B; D++){
        sigma += factorial(D);
    }
    return A * B / (double)(B + power(C, 2)) + 1.0 * sigma;
}


#endif/*math_h*/
