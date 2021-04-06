#include<stdio.h> 
#include"triangle.h"
#define areytriangle_h
#ifdef areytriangle_h
#define MAX_NUM 10

typedef struct {
	Tria** storage;
	long count;
} AreyTria;

AreyTria* createAreyTria(long preservedCount);

long countArray(AreyTria* a);
int IndexTriaInsert (AreyTria* l, int index, Tria* tria);
Tria* getTriaAtArey(AreyTria* l, int index);


void deleteAreyTria(AreyTria* l);
void PutTriangleInArey(AreyTria* ar, Tria* t);
 void printAreyTria(AreyTria* l);

 double SumPerimOfArayTria(AreyTria* ar);
 double SumSqyarefArayTria(AreyTria* ar);
// Прототип функции

#endif // !TEA_H