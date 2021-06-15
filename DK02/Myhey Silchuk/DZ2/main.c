#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Figure.h"

int main()
{
    Kolo *kolo = createKolo(0, 0, 5, 12);
  //  SetPoint(kolo->Center);
    printKolo(kolo);
    SetPoint(kolo->Radius);
    printKolo(kolo);
    float radius = RadiusCheck(kolo);
    printf("Radius is %0.3f", radius);
    FreeKolo(kolo);

}
