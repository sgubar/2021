#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

double rad(double x1,double x2, double y1, double y2) {
    double q;
    struct center {
       double x1;
       double y1;
    };
    struct circle {
        double x2;
        double y2;
    };
    q=sqrtl((x2-x1)+(y2-y1));
    return q;
};

double posh(q){
    q=q*q*3.14;
    return q;
};

double o(q){
    q=6.28*q;
    return q;
};
