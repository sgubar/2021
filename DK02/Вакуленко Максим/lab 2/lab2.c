
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include"list.h"

int main() {
	FILE* fPointer;
	fopen_s(&fPointer, "sample.txt", "r");
	char sumb;
	if (fPointer == NULL) {
		printf("Error. fPointer == NULL\n");
		return 0;
	}

	DoubleCharList* sample = createDoubleCharList();
	while ((sumb = fgetc(fPointer)) != EOF) {

		addCharValueToDoubleCharList(sample, sumb);

		if (sumb == '\n' || sumb == '\0') {
			printRevDoubleCharList(sample);
			reFreshDoubleCharList(sample);
		}

	}
	printf("\n");
	printRevDoubleCharList(sample);
	deleteDoubleCharList(sample);

	fclose(fPointer);
	return 0;
}
