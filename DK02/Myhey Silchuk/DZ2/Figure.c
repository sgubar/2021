
#include "Figure.h"
#include <stdio.h>
#include <math.h>

Point *createPoint(float x, float y)
    {
        Point *point = (Point *)malloc(sizeof(Point));
        if(point != NULL)
        {
        point->x = x;
        point->y = y;
        }
        return point;
    };

Kolo *createKolo(float center_x,float center_y, float radius_x, float radius_y)
    {
        Kolo *kolo = (Kolo*)malloc(sizeof(Kolo));
        Point *KoloCenter = createPoint(center_x, center_y);
        Point *KoloRadius = createPoint(radius_x, radius_y);
        kolo->Center = KoloCenter;
        kolo->Radius = KoloRadius;

    };

void printPoint(Point *point)
    {
        printf("X is %f\nY is %f\n", point->x, point->y );
    };
void printKolo(Kolo *kolo)
    {
        printPoint(kolo->Center);
        printPoint(kolo->Radius);

    };
void SetPoint(Point *point)
{
    float x, y;
    printf("New x = ");
    scanf("%f", &x);
    printf("New y = ");
    scanf("%f", &y);
    point->x = x;
    point->y = y;


}

float RadiusCheck(Kolo *kolo)
{
    float radius;
    float a,b,c;
    a = (kolo->Radius->x) - (kolo->Center->x);
    b = (kolo->Radius->y) - (kolo->Center->y);
    c = pow(a,2) + pow(b,2);
    radius = sqrt(c);
    return radius;
}

void FreePoint(Point *point)
{
    if(point != NULL)
    {
    point = NULL;
    free(point);
    }
}

void FreeKolo(Kolo *kolo)
{
    if(kolo != NULL)
    {
        FreePoint(kolo->Center);
        FreePoint(kolo->Radius);
        free(kolo);
    }
}

