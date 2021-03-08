#include "linesPriam.h"

#define ArrayPriam_H
#ifdef ArrayPriam_H

#define maxnumber 8


typedef struct {
	Priam* priamokut[maxnumber];
}PriamArray;


PriamArray* createPriamArray (void);
int counterpriamokut(PriamArray* number);
void addPriamToArray(PriamArray* number, Priam* pri);
void printPriamArray(PriamArray* number);
double FullploshaPriam(PriamArray* number);
void deletePriamArray(PriamArray* number);



#endif