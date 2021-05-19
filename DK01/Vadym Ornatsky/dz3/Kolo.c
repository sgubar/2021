#include "Kolo.h"
#include <stdlib.h>

Kolo* createKoloByCentreAndRadius(Point* centre_, float radius_) {
	if (NULL == centre_) {
		return NULL;
	}
	Kolo* kolo = (Kolo*)malloc(sizeof(Kolo));
	if (NULL != kolo) {
		if (0 < radius_) {
			kolo->centre = createPoint(centre_->x, centre_->y);
			kolo->radius = radius_;
		}
		else { 
			return NULL;
		}
	}
	return kolo;
}



Kolo* createKoloByCentreAndTochka(Point* centre_, Point* tochka_) {
	if (NULL == centre_ || NULL == tochka_) {
		return NULL;
	}
	float radius = getDistance(centre_, tochka_);
	if (0 == radius) {
		return NULL;
	}
	Kolo* kolo = (Kolo*)malloc(sizeof(Kolo));
	if (NULL != kolo) {
		kolo->radius = radius;
		kolo->centre = createPoint(centre_->x, centre_->y);
	}
	return kolo;
}

void deleteKolo(Kolo* kolo) {
	if (NULL != kolo) {
		deletePoint(kolo->centre);
		free(kolo);
	}
}

Kolo* copyKolo(Kolo* kolo) {
	if (NULL == kolo) {
		return NULL;
	}
	return createKoloByCentreAndRadius(kolo->centre, kolo->radius);
}

void printKolo(Kolo* kolo) {
	if (NULL != kolo) {
		printf("Centre X: %i \n", kolo->centre->x);
		printf("Centre Y: %i \n", kolo->centre->y);
		printf("Radius: %f \n", kolo->radius);
	}
}