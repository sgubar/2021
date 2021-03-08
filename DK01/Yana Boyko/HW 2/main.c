#include <stdio.h>
#include "areytriangle.h"

int main()

{

    // AreyTria *One = createAreyTria();
    // PutTriangleInArey(One, createTriangleByPoints(createPoint(0, 0), createPoint(0, 1), createPoint(0, 0))); // wrong tria just will skip
    // PutTriangleInArey(One, createTriangleByPoints(createPoint(1, 0), createPoint(0, 0), createPoint(0, 1)));
    // PutTriangleInArey(One, createTriangleByPoints(createPoint(2, 0), createPoint(0, 0), createPoint(2, 1)));
    // printAreyTria(One);
    // deleteAreyTria(One);
    // One = NULL;
    // printAreyTria(One);
  
    Tria *One = createTriangleByPoints(createPoint(0, 0), createPoint(0, 1), createPoint(0, 2));
    printTriange(One);
    deleteTria(One);
    One = NULL;
    return 0;

}
