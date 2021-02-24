#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "dk_tools.h"

int main(int argc, char *argv[]) {
	//test
	printf("%d\n", get_chrs_pos(argv[1], argv[2], strlen(argv[1]), strlen(argv[2])));
}
