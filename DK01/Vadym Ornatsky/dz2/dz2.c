
#include "Kolo.h"
#include <stdio.h>

int main(int argc, const char* argv[]){
	Point* centre = createPoint(0, 0);
	Point* tochka = createPoint(10, 0);

	Kolo* kolo1 = createKoloByCentreAndRadius(centre, 5);
	Kolo* kolo2 = createKoloByCentreAndTochka(centre, tochka);
	Kolo* copy = copyKolo(kolo1);
	printf("Kolo1: \n");
	printKolo(kolo1);
	printf("Kolo2: \n");
	printKolo(kolo2);
	printKolo(copy);


	deleteKolo(kolo1);
	deleteKolo(kolo2);
	deleteKolo(copy);
	deletePoint(centre);
	deletePoint(tochka);
}

