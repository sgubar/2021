#include <stdio.h>

#include "KoloArray.h"

int main() {
    Point* centre1 = createPoint(-25,0);
    Point* centre2 = createPoint(0,0);
    Point* centre3 = createPoint(25,0);
    Point* centre4 = createPoint(-12,-15);
    Point* centre5 = createPoint(12,-15);
    float basicRadius = 10.;
    T_KoloArray* olympicRings = CreateKoloArray(3);
    Kolo* blueRing = createKoloByCentreAndRadius(centre1, basicRadius);
    Kolo* blackRing = createKoloByCentreAndRadius(centre2, basicRadius);
    Kolo* redRing = createKoloByCentreAndRadius(centre3, basicRadius);
    Kolo* yellowRing = createKoloByCentreAndRadius(centre4, basicRadius);
    Kolo* greenRing = createKoloByCentreAndRadius(centre5, basicRadius);
    InsertKoloToArray(olympicRings, blueRing);
    InsertKoloToArrayByIndex(olympicRings, redRing, 2);
	PrintKoloArray(olympicRings);

    InsertKoloToArray(olympicRings, blackRing);
	PrintKoloArray(olympicRings);

	InsertKoloToArray(olympicRings, yellowRing);
	PrintKoloArray(olympicRings);
	
	InsertKoloToArrayByIndex(olympicRings, greenRing, 4);
	PrintKoloArray(olympicRings);

	printf("Begin cleaning\n");

	DeleteKoloArray(olympicRings);
	deleteKolo(blueRing);
	deleteKolo(blackRing);
	deleteKolo(redRing);
	deleteKolo(yellowRing);
	deleteKolo(greenRing);
	deletePoint(centre1);
	deletePoint(centre2);
	deletePoint(centre3);
	deletePoint(centre4);
	deletePoint(centre5);

    return 0;
}