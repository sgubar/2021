#include "RectangleArray.h"


int main(int argc, const char* argv[]) {

	Rectangle* rec = createRectangleByCoords(0, 0, 0, 4, 6, 4, 6, 0);
	Rectangle* res = createRectangleByCoords(0, 0, 0, 4, 6, 4, 6, 0);
	Rectangle* raw = createRectangleByCoords(1, 1, 1, 4, 6, 4, 6, 1);
	RectangleArray* wow = createRectangleArray();
	printRectangle(rec);
	printRectangle(res);
	printRectangle(raw);
	addRectangleToRectangleArray(wow, rec);
	addRectangleToRectangleArray(wow, res);
	addRectangleToRectangleArray(wow, raw);
	printf("Is equal rec and res?: %d\n", isEqualRectangle(rec, res));
	printf("the count of rectangles in array: %d\n", countRectangles(wow));
	printf("Sum perimeter of all rectangles: %f\n", FullPerimeterRectangleArray(wow));
	printf("Sum squares of all rectangles: %f\n", FullSquareRectangleArray(wow));
	deleteRectangleArray(wow);
}