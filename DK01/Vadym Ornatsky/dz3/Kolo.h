#pragma once

#include "Point.h"

typedef struct tag_kolo {
	Point* centre;
	float radius;
} Kolo;

Kolo* createKoloByCentreAndRadius(Point* centre_, float radius_);
Kolo* createKoloByCentreAndTochka(Point* centre_, Point* tochka_);
Kolo* copyKolo(Kolo* kolo);
void deleteKolo(Kolo* kolo);
Kolo* copyKolo(Kolo* kolo);
void printKolo(Kolo* kolo);