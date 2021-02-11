#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tools.h"

int main(int argc, char *argv[]) {
	//test
	printf("%d\n", get_chrs_pos(argv[1], argv[2], strlen(argv[1]), strlen(argv[2])));
	
	int *a = (int *) malloc(sizeof(int) * 3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;

	a = (int *) rearrange(a, 3, Int);

	for(int i = 0; i < 3; i++)
		printf("%d\n", *(a + i));
}
