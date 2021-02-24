#include <stdio.h> 
int main(void) 
{ 
    int s;
    int w=0;
    {
        printf("Введите свое предложение: ");
        scanf("%d", &s);
    }
    while ((s = getchar()) != EOF) 
    { 
        if (s == ' ' || s == '\n') 
         { 
             w++; 
             } 
             } 
             printf("\n Слова: %u\n", w);

             return 0;
              }
