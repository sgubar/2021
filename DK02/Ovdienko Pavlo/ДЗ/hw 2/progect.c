#include "Rectangle.h"


int main(int argc, const char* argv[]) {


	Rectangle* rec = createRectangleByCoords(0, 0, 0, 4, 6, 4, 6, 0);
	Rectangle* res = createRectangleByCoords(0, 0, 0, 4, 6, 4, 6, 0);
	printRectangle(rec);
	printRectangle(res);
	isEqualRectangle(rec, res);
	deleteRectangle(rec);
	deleteRectangle(res);
}