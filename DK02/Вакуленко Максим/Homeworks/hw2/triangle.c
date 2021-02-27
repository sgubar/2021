#include"triangle.h"
#include<stdlib.h>
#include <math.h>
Tria* createTriangleByPoints(PtCord* point1, PtCord* point2, PtCord* point3) {
	Line* Line1_2 = createLineByPoints(point1, point2);
	Line* Line2_3 = createLineByPoints(point2, point3);
	Line* Line1_3 = createLineByPoints(point1, point3);
	Tria* triangle = (Tria*)malloc(sizeof(Tria));
	if (NULL == Line1_2 || NULL == Line2_3 || NULL == Line1_3) {
		return NULL;
	}
	else if (TestOfLife(point1, point2, point3) == 0) {
		return NULL;
	}
		triangle->line_1 = copyLine(Line1_2);
		triangle->line_2 = copyLine(Line2_3);
		triangle->line_3 = copyLine(Line1_3);
		deledeLine(Line1_2);
		deledeLine(Line2_3);
		deledeLine(Line1_3);
		return triangle;
	
	
}

int TestOfLife(PtCord* point1, PtCord* point2, PtCord* point3) {
	if (isEqualPoints(point1, point2) == 1 || isEqualPoints(point1, point3) == 1 || isEqualPoints(point2, point3) == 1) {
		return 0;
	}
	return 1;
}

double PerimeterOfTriangle(Tria* Per) {
	if (Per != NULL) {
		return (lenghtLine(Per->line_1) + lenghtLine(Per->line_2) + lenghtLine(Per->line_3));
	}
	else { return 0; }
}


double SquareOfTriangle(Tria* Per) {//Формула герона
	if (Per != NULL) {
		return sqrt((PerimeterOfTriangle(Per) / 2) * (PerimeterOfTriangle(Per) / 2 - lenghtLine(Per->line_1)) * (PerimeterOfTriangle(Per) / 2 - lenghtLine(Per->line_2)) * (PerimeterOfTriangle(Per) / 2 - lenghtLine(Per->line_3)));
	}
	else { return 0; }
}


void DrawTriangle() {
	printf("\n");
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < (4 - i); j++) {
			printf(" ");
		}
		
		printf("/");
		if (i != 4) {
			for (int b = 1; b < i; b++) {
				printf("  ");
			}
		}
		if (i == 4) {
			for (int c = 1; c < i; c++) {
				printf("__");
			}

		}
			printf("\\");
		printf("\n");
	}
	printf("\n");
}
void deleteTria(Tria* l) {
	if (l != NULL) {
		deledeLine(l->line_1);
		deledeLine(l->line_2);
		deledeLine(l->line_3);		
	}
}

Tria* copyTria(Tria* t) {
	if (t == NULL) {
		return;
	}
	Tria* Copy = createTriangleByPoints(copyPoint(t->line_1->A), copyPoint(t->line_2->A), copyPoint(t->line_2->B));
	return Copy;
}

void printTriange(Tria* test) {
	if (test == NULL) {
		printf("Error_Print_Triangle\n");
		return 0;
	}
	DrawTriangle();
	printf("Line_1: ");
	printLine(test->line_1);
	printf("Leight: %lf \n", lenghtLine(test->line_1));
	printf("Line_2: ");
	printLine(test->line_2);
	printf("Leight: %lf \n", lenghtLine(test->line_2));
	printf("Line_3: ");
	printLine(test->line_3);
	printf("Leight: %lf \n", lenghtLine(test->line_3));
	printf("Perimetr: %lf\n ", PerimeterOfTriangle(test));
	printf("Square: %lf\n", SquareOfTriangle(test));
}