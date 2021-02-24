
#include"line.h"
#define triangle_h
#ifdef triangle_h
#include<stdio.h> 
typedef struct {
	Line* line_1;
	Line* line_2;
	Line* line_3;
} Tria;

Tria* createTriangleByLine(Line* ln1, Line* ln2, Line* ln3);
void deleteTria(Tria* l);
void printLine(Line* l);
double lenghtLine(Line* l);
int TestOfLife(Line* ln1, Line* ln2, Line* ln3);
double PerimeterOfTriangle(Tria* Per);
double SquareOfTriangle(Tria* Per);
void printTriange(Tria* test);
void DrawTriangle();

// Прототип функции

#endif // !TEA_H
