#include"dk_tool.h"
void rand_arr(int arr[lev][lon_g]) {
    int l = 0, j = 0, g;
    while (l < lev) {
        while (j < lon_g) {
            arr[l][j] = rand() % 20;;
            j = j + 1;
        }
        j = 0;
        l = l + 1;
    }
}

void matr(int a[lev][lon_g]) {
    int b = 0, i;
    while (b < lev) {
        i = 0;
        while (i < lon_g) {
            printf(" %d ", a[b][i]);
            i++;
        }
        b++;
        printf("\n");
    }
}

void num_mass(int num, int a[lev][lon_g]) {
    for (int f = 0; f < lev; f++) {
        for (int i = 0; i < lon_g; i++) {
            int last = a[f][i];
            a[f][i] = last * num;
            last = 0;
        }
    }
}