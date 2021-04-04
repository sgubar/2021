#include"areytriangle.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

void internalAddTria(AreyTria* l, Tria* p);

AreyTria* createAreyTria(void) {
	AreyTria* t = (AreyTria*)calloc(MAX_NUM, sizeof(AreyTria));
}

int countArey(AreyTria* l) {
	if (NULL == l) {
		return 0;
	}

	int count = 0;

	for (count = 0; count < MAX_NUM; count++) {
		if (l->arrey[count] == NULL) {
			break;
		}
	}

	return count;
}
 
void internalAddTria(AreyTria* l, Tria* p) {
	if (l == NULL || p == NULL) {
//		printf("Error internalAddTria \n");
		return;
	}
	int count = countArey(l);
	if (count < MAX_NUM) {
		l->arrey[count] = copyTria(p);
	}
}

void deleteAreyTria(AreyTria* l) {
	if (NULL != l) {

		for (int i = 0; i < MAX_NUM; i++) {
			if (l->arrey[i]!= NULL) {
				//printf("delete el start %d\n", i);
				deleteTria(l->arrey[i]);
			//	printf("delete el done %d\n", i);
			}
				
		}
			
    }
	free(l);
}

void PutTriangleInArey(AreyTria* ar, Tria* t) {
	if (t == NULL) {
		printf("Error Puting Triangle In Arey\n");
		return;
  }
	internalAddTria(ar, t);
}

void printAreyTria(AreyTria* l) {
	if (NULL == l) {
		printf("Print1 done \n");
		return;
	}

	for (int i = 0; i < MAX_NUM && l->arrey[i] != NULL; i++) {
			printf("Triagle%d \n", (i+1));
			printTriange(l->arrey[i]);
		    
	}
	printf("Sum perimeter of all Arrey: %lf\n", SumPerimOfArayTria(l));
	printf("Sum square of all Arrey: %lf\n", SumSqyarefArayTria(l));
	printf("\n\n");
}


double SumPerimOfArayTria(AreyTria* ar) {
	if (NULL == ar) {
		return;
	}
	double perimeter = 0;
	for (int i = 0; i < MAX_NUM && ar->arrey[i] != NULL; i++) {
			perimeter += PerimeterOfTriangle(ar->arrey[i]);
	}
	return perimeter;
}
double SumSqyarefArayTria(AreyTria* ar) {
	if (NULL == ar) {
		return;
	}
	double Square = 0;
	for (int i = 0; i < MAX_NUM && ar->arrey[i] != NULL; i++) {
		Square += SquareOfTriangle(ar->arrey[i]);
	}
	return Square;
}
