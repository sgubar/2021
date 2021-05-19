#ifndef KOLO_ARRAY
#define KOLO_ARRAY

#include "Kolo.h"

typedef struct KoloArray {
    Kolo** arrayData;
    unsigned int count;
} T_KoloArray;

T_KoloArray* CreateKoloArray(unsigned int size_);
void DeleteKoloArray(T_KoloArray* array_);
int InsertKoloToArray(T_KoloArray* array_, Kolo* element_);
int InsertKoloToArrayByIndex(T_KoloArray* array_, Kolo* element_, unsigned int index_);
void PrintKoloArray(T_KoloArray* array_);

#endif