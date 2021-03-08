#include <stdio.h>
#include "line.h"
#define triangle_h
#ifdef triangle_h

typedef struct
{
    Line *line_1;

    Line *line_2;

    Line *line_3;
} Tria;

Tria *createTriangleByPoints(PtCord *point1, PtCord *point2, PtCord *point3);

int TestOfLife(PtCord *point1, PtCord *point2, PtCord *point3);

void deleteTria(Tria *l);

double PerimeterOfTriangle(Tria *Per);

double SquareOfTriangle(Tria *Per);

void printTriange(Tria* test);

void DrawTriangle();

Tria *copyTria(Tria *t);


#endif // !TEA_H
