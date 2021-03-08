#include <stdlib.h>
#include <stdio.h>
#define POINT_H
#ifdef POINT_H

typedef struct
{
    int x;

    int y;
} PtCord;
PtCord *createPoint(int x, int y);

void deletePoint(PtCord *p);
void printPoint(PtCord *p);

PtCord *copyPoint(PtCord *p);

int isEqualPoints(PtCord *lp, PtCord *rp);


#endif
