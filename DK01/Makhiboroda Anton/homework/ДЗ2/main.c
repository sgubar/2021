#include "Rectangle.h"


int main(int argc, const char* argv[]) {


	Rectangle* rec = createRectangleByCoords(0, 0, 0, 5, 7, 5, 7, 0);
	Rectangle* res = createRectangleByCoords(0, 0, 0, 5, 7, 5, 7, 0);
	printRectangle(rec);
	printRectangle(res);
	isEqualRectangle(rec, res);
	deleteRectangle(rec);
	deleteRectangle(res);
}
