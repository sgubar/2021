#include <stdlib.h>
#include <stdio.h>

void sum(int *b, int j, int t){
	if (b[j] + t > 9){
			int l = b[j] + t;
			b[j] = l % 10;
			sum(b, j-1, (l/10));
		}else  b[j]+=t;
}

void fac(int *a, int *b, int k){
    int n = 170;
    int i = 1;
    while(i<=k){
        int j = n-1;
        while(j>=0){
		    int t = a[j] * i;
		    if (t>9){
		        sum(b, j, t % 10);
		        sum(b, j-1, t / 10);
		    }else sum(b, j, t);
		    j--;
		}
		
		j = n-1;
		while(j>=0){
	        a[j] = b[j];
	        b[j] = 0;
	        j--;
	    }
	    i++;
	}
	int j = 0;
	int flag = 0;
	printf("%d%s", i-1, "! ");
    while(j<n){
		if (a[j]!=0) flag=1;
		if (flag)
		printf("%d", a[j]);
		j++;
	}
	printf("\n");
}

void suma(int *Q, int A, int C){
    int n = 170;
    int b[n];
    int a[n];
	memset(b, 0, sizeof(b));
	int D=0;
	while(D<=C){
        int i = 0;
        while(i<n){
        	a[i] = 0;
        	i++;
		}
        a[n-1] = 1;
        fac(a, b, (A+D));
        int j=0;
        while(j<n){
            sum(Q, j, a[j]);
            j++;
        }
        D++;
    }
    printf("\nСумма факториалов: ");
    int flag = 0;
    int j = 0;
    while(j<n){
		if (Q[j]!=0) flag=1;
		if (flag)
		printf("%d", Q[j]);
		j++;
	}
}
