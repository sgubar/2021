#include <stdio.h>
#include "line.h"

int main(int argc, const char * argv[])
{
	Point A = {2,3};
	Point B = {4,6};
  Point C = {10,7};
	
	Line *AB = createLine(&A, &B);
	printf("The length of Line AB = %f\n", lenghLine(AB));
  Line *BC = createLine(&B, &C);
  printf("The length of Line BC = %f\n", lenghLine(BC));
  Line *CA = createLine(&C, &A);
  printf("The length of Line CA = %f\n", lenghLine(CA));
	
	// insert code here...
	printf("Hello, World!\n");

	destroyLine(AB);
  destroyLine(BC);
  destroyLine(CA);
	return 0;
}
