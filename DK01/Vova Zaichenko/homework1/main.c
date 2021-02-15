#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tools.h"

int main(int argc, char *argv[]) 
{

	if(strcmp(argv[1], "--make-matrix") == 0) 
	{

		int r = conv_to_int(argv[2]); 
		int c = conv_to_int(argv[3]); 

		int** matrix = make_matrix(r, c); 

		for(int i=0; i < r; i++) 
		{
			for(int j=0; j < c; j++)
			
			{
				printf("Enter number at %d, %d: ", r, c); 
				scanf("%d", &matrix[i][j]); 
			}
		}
		
		printf("\nMatrix:\n");

		for(int i=0; i < r; i++) 
		{
			for(int j=0; j < c; j++)
			{
				printf("%d ", matrix[i][j]); 
			}
			printf("\n"); 
		}

		del_matrix(matrix, r); 
		printf("\nMatrix deleted away!\n"); 
	}
	else if(strcmp(argv[1], "--find") == 0) 
	{

		int pos = find_chars(argv[2], argv[3]); 
	
	
		printf("Position: %d\n",pos); 
	else if(strcmp(argv[1], "--str-buffer") == 0)
	{

		int len = str_buffer(argv[2]); 
		printf("Length: %d\n",len); 
	}
}
