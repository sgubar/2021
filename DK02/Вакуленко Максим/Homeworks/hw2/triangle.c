#include"triangle.h"
#include<stdlib.h>
#include <math.h>
Tria* createTriangleByLine(Line* ln1, Line* ln2, Line* ln3) {
	if (NULL == ln1 || NULL == ln2 || NULL == ln3) {
		return NULL;
	}
	else if (TestOfLife(ln1, ln2, ln3) == 0) {
		return NULL;
	}
	Tria* triangle = (Tria*)malloc(sizeof(Tria));
		triangle->line_1 = copyLine(ln1);
		triangle->line_2 = copyLine(ln2);
		triangle->line_3 = copyLine(ln3);
		return triangle;
	
	
}

int TestOfLife(Line* ln1, Line* ln2, Line* ln3) {
	if (lenghtLine(ln1) + lenghtLine(ln2) < lenghtLine(ln3) || lenghtLine(ln1) + lenghtLine(ln3) < lenghtLine(ln2) || lenghtLine(ln3) + lenghtLine(ln2) < lenghtLine(ln1)) {
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

void DrawTriangle(){
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < (4 - i); j++) {
			printf(" ");
		}
		for (int y = 0; y < i; y++) {
			printf("/");
		}
		printf("");
		for (int y = 0; y < i; y++) {
			printf("\\");
		}
		printf("\n");
	}
}
void deleteTria(Tria* l) {
	if (l != NULL) {
		deledeLine(l->line_1);
		deledeLine(l->line_2);
		deledeLine(l->line_3);		
	}
}

void printTriange(Tria* test) {
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