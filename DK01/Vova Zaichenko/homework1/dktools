#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dk_tools.h"

int** make_matrix(int r, int c)
{
	if(c <=0 || r <= 0)
	{
		return NULL;
	}

	int** matrix = (int**)malloc(sizeof(int*) * r);
	for(int i=0; i < r; i++)
	{
		*(matrix+i) = (int*)malloc(sizeof(int) * c);
	}

	return matrix;
}

void del_matrix(int** matrix,int r)
{
	if(matrix==NULL)
	{
		return;
	}

	for(int i=0; i < r; i++)
	{
		free( *(matrix+i) );
	}

	free(matrix);
}

int find_chars(char* chars, char* str)
{
	char* tmp = (char*)malloc(strlen(chars) + 1);
	int fin = strlen(str)-(strlen(chars) - 1);
	*(tmp + strlen(chars))='\0';
	for(int i=0; i < fin; i++)
	{
		for(int j=0; j < strlen(chars); j++)
		{
			tmp[j] = str[i + j];
		}
		if(strcmp(chars, tmp)==0)
			return i;

	}
	return -1;
}

int str_buffer(char* in_buffer)
{
	if(in_buffer==NULL)
	{
		return -1;
	}

	int result = 0;
	while(*in_buffer != '\0')
	{
		in_buffer++;
		result++;
	}

	return result;
}

int conv_to_int(char* str)
{
	int st = 1;
	int tmp;
	int result;

	for(int i = strlen(str) - 1; i >= 0; i--)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			if(i ==  strlen(str) - 1)
			{
				result = str[i]-'0';
			}
			else
			{	
				st*=10;
				result+=st * (str[i]-'0');
			}
		}
		else
		{
			return -1;
		}
	}

	return result;
}
