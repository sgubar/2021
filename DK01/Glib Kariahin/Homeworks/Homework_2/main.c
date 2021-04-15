#include <stdio.h>

//  ^
//  |Y
//  |        ************
//  |     *** |          ***
//  |    *----|---a---------*
//  |     *** |b         ***
//  |        ************                X
//  -------------------------------------->


#include "point.h"
#include "Ellipse.h"

int main(int argc, const char * argv[]) {


    //Creating objects for work
    Point* f1 = createPoint(5,0);
    Point* f2 = createPoint(-5,0);



    Ellipse *ellipse = createEllipseByCoords(5,-5,13,12);
    Ellipse *ellipse2 = createEllipseByFocuses(f1,f2,13,12);
    //Let's check if user use not correct data?
    Ellipse *fakeEllipse = createEllipseByCoords(45,-4565,13,12);
    if(NULL == fakeEllipse){
        //This message will be printed.
        printf("This is a fake ellipse!");

    }

    //Printing of objects
    printf("Ellipses :  \n");
    printEllipse(ellipse);
    printEllipse(ellipse2);
    printf("\n");

    //Copy of object
    Ellipse *copy = copyEllipse(ellipse);

    //Printing of objects
    printEllipse(copy);
    printf("\n");

    //Equality of objects
    printf("is equal ellipse 2: %d\n", isEqualEllipse(ellipse2, copy));
    printf("is equal ellipse  : %d\n", isEqualEllipse(ellipse, copy));

    //Printing ellipses data
    printf("len1: %f\n", focusLenght(ellipse));
    printf("len2: %f\n", focusLenght(ellipse2));

    //Deleting a object after work with them
    deleteEllipse(ellipse);
    deleteEllipse(ellipse2);
    deleteEllipse(copy);
    deletePoint(f1);
    deletePoint(f2);

    return 0;
}
