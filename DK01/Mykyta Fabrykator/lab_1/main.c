#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "Fun.h"

const int n = 170;

void print_Q(int *Q, double t){
    char buf[10];
	gcvt (t, 5, buf);
    int flag = 0;
    printf("\n\nQ: ");
    int i=0;
    while(i<n){
		if (Q[i]!=0) flag=1;
		if (flag)
		printf("%d", Q[i]);
		i++;
	}
	int j=0;
	flag = 0;
	while(buf[j]!=NULL){
	    if(buf[j]=='.' || buf[j]==',') flag=1;
	    if (flag)
	    printf("%c", buf[j]);
	    j++;
	}
}

int scan(){
    int x=0, i=0;
    char n[1000];
    do{
        scanf("%s", n);
        i=0;
        while (n[i]!=NULL){
            i++;
        }
        x = atoi(n);
        if(i>2 || x>=50 || x<=0) printf("Число введено неверно\nПопробуйте ещё раз: ");
    }while(i>2 || x>=50 || x<=0);
    return x;
}

int main(){
	setlocale(LC_ALL, "Russian");
    int Q[n];
	memset(Q, 0, sizeof(Q));
	int A=0,B=0,C=0;
	
	printf("Введите число А(0<A<50): ");
	A=scan();
	printf("Введите число B(0<B<50): ");
	B=scan();
	printf("Введите число C(0<C<50): ");
	C=scan();

    suma(Q, A, C);
	double t = (A*(sqrt(B+C)/B));
	printf("\n%s%f", "A*sqrt(B+C)/B: ", t);
	sum(Q, n-1, (int)t);
	
	print_Q(Q, t);
	
    return 0;
}
