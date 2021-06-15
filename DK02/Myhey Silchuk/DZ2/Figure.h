#ifndef Figure_h
#define Figure_h
#include <stdio.h>
#include <math.h>

typedef struct Point{
    float x;
    float y;
    }Point;

typedef struct Kolo{
    Point *Center;
    Point *Radius;
    }Kolo;

Point *createPoint(float x, float y);
Kolo *createKolo(float center_x,float center_y, float radius_x, float radius_y);
void printPoint(Point *point);
void printKolo(Kolo *kolo);
void FreePoint(Point *point);
void FreeKolo(Kolo *kolo);
void SetPoint(Point *point);
float RadiusCheck(Kolo *kolo);













#endif /*Figure_h*/
