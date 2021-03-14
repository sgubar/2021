#include "rectangle.h"


int main(int argc, const char* argv[]) {

	Rectangle* rec = createRectangleByCoords(0, 0, 0, 4, 6, 4, 6, 0);
	Rectangle* res = createRectangleByCoords(0, 0, 0, 4, 6, 4, 6, 0);
	Rectangle* raw = createRectangleByCoords(1, 1, 1, 4, 6, 4, 6, 1);
	printRectangle(rec);
	printRectangle(res);
	printRectangle(raw);
	printf("Is equal rec and res?: %d\n", isEqualRectangle(rec, res));
	deleteRectangle(rec);
	deleteRectangle(res);
	deleteRectangle(raw);
}