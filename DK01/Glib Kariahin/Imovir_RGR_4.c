#include <stdio.h>
#include <math.h>
int main() {

    double p = 0.0025;
    double n = 100;
    double k = 1;

    double x = (k-n*p)/sqrt(n*p*(1-p));

    double f = (1/sqrt(3.1415*2))*pow(2.71828,-(x*x/2));

    double P = (1/sqrt(n*p*(1-p)))*f;

    printf("Result : %f",P);

return 0;
}
