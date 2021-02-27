#include "RectangleArray.h"


int main(int argc, const char* argv[]) {

	Rectangle* rec = createRectangleByCoords(0, 0, 0, 4, 6, 4, 6, 0);
	Rectangle* res = createRectangleByCoords(0, 0, 0, 4, 6, 4, 6, 0);
	Rectangle* raw = createRectangleByCoords(1, 1, 1, 4, 6, 4, 6, 1);
	RectangleArray* wow = createRectangleArray();
	addRectangleToRectangleArray(wow, rec);
	addRectangleToRectangleArray(wow, res);
	addRectangleToRectangleArray(wow, raw);
	printf("%d\n", isEqualRectangle(rec, res));
	printf("%d\n", countRectangles(wow));
	printf("%f\n", FullPerimeterRectangleArray(wow));
	printf("%f\n", FullSquareRectangleArray(wow));
	deleteRectangleArray(wow);
}