#include<stdio.h>
#include"point.h"
#define LINE_H
#ifdef LINE_H
 
typedef struct {
	PtCord* A;
	PtCord* B;
} Line;

Line* createLineByPoints(PtCord* p1, PtCord* p2);
Line* copyLine(Line* l);
void deledeLine(Line* l);
void printLine(Line* l);
int isEqualLine(Line* ll, Line* rl);
double lenghtLine(Line *l);

// Прототип функции

#endif // !TEA_H