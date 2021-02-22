#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int arr_rez[100][100];

int formula(int a, int arr1[][a], int arr2[][a])
{
    int val=0;
    for(int i=0; i<a; i++)
        for(int j =0; j<a; j++)
        {
            for(int k=0; k<a; k++)
                val = val+arr1[i][k]*arr2[k][j];
            arr_rez[i][j] = val;
            val = 0;
        }
    return 0;
}

int main()
{
    srand (time(NULL));
    int a= 0;
    int asv = 0;
    printf("enter the lenght of side a matrix: ");
    scanf("%d",&a);
    int arr1[a][a];
    int arr2[a][a];
    printf("use random?(1/0): ");
    scanf("%d",&asv);
    if(asv)
    {
        for(int i=0; i<a; i++)
            for(int j=0; j<a; j++)
            {
                arr1[i][j] = rand()%99+1;
                arr2[i][j] = rand()%99+1;
            }
    }
    else
        for(int i=0; i<a; i++)
            for(int j=0; j<a; j++)
            {
                printf("enter the arr1[%d][%d]: ", i, j);
                scanf("%d", &arr1[i][j]);
                printf("enter the arr2[%d][%d]: ", i, j);
                scanf("%d", &arr2[i][j]);
            }
    printf("our 2 matrix: \n");
    for(int i=0; i<a; i++)
    {
        printf("|");
        for(int j=0; j<a; j++)
        {
            printf("%3d ",arr1[i][j]);
        }
        printf("|\n");
    }
    printf("\n\n");
    for(int i=0; i<a; i++)
    {
        printf("|");
        for(int j=0; j<a; j++)
        {
            printf("%3d ",arr2[i][j]);
        }
        printf("|\n");
    }

    formula(a, arr1, arr2);

    printf("\nrez:\n");
    for(int i=0; i<a; i++)
    {
        printf("|");
        for(int j=0; j<a; j++)
        {
            printf("%3d ",arr_rez[i][j]);
        }
        printf("|\n");
    }
    return 0;
}
