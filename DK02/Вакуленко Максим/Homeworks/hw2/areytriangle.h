#include<stdio.h> 
#include"triangle.h"
#define areytriangle_h
#ifdef areytriangle_h
#define MAX_NUM 10

typedef struct {
	Tria* arrey[MAX_NUM];
} AreyTria;

AreyTria* createAreyTria(void);

int countArey(AreyTria* l);

void deleteAreyTria(AreyTria* l);
void PutTriangleInArey(AreyTria* ar, Tria* t);
 void printAreyTria(AreyTria* l);

 double SumPerimOfArayTria(AreyTria* ar);
 double SumSqyarefArayTria(AreyTria* ar);
// Прототип функции

#endif // !TEA_H