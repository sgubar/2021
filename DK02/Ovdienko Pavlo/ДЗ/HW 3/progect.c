#include "RectangleArray.h"


int main(int argc, const char* argv[]) {

	RectangleArray* wow = createRectangleArray(10);
	printRectangleArray(wow);
	Rectangle* rec = createRectangleByCoords(0, 0, 0, 4, 6, 4, 6, 0);
	Rectangle* res = createRectangleByCoords(0, 0, 0, 4, 6, 4, 6, 0);
	setRectangleAtIndex(wow, rec, 0);
	addRectangleToRectangleArray(wow, res);
	printRectangleArray(wow);
	deleteRectangleArray(wow);
}