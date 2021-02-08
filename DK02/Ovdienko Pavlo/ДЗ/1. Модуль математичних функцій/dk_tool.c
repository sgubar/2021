#include "dk_tool.h"
#include <math.h>

int strlen_buffer(char* buffer)
{
	int result = 0;
	while ((*buffer != '\n') && (*buffer != '\0'))
	{
		result++;
		buffer++;
	}
	return result;
}



int peretvorenna_chisla(char* ty)
{
	int i = 0, result=0, g= strlen_buffer(ty)-1;

	for (i = 0; i <= strlen_buffer(ty)-1; i++)
	{
		printf("%d\n", i);
		if ((ty[i] >= 65) && (ty[i]) <= 70)
		{
			ty[i] = (int)ty[i] - 55;
		}
		else if ((ty[i] >= 97) && (ty[i] <= 102))
		{
			ty[i] = ty[i] - 87;
		}
		else if ((ty[i] >= 48) && (ty[i] <= 57))
		{
			ty[i] = ty[i] - 48;
			if (i == 0)
			{
				break;
				i++;
				g--;
			}
		}
		else if (((ty[i] >= 16) && (ty[i] <= 47)) || ((ty[i] >= 58) && (ty[i] <= 64)) || ((ty[i] >= 71) && (ty[i] <= 96)) || ((ty[i] >= 103) && (ty[i] <= 127)))
		{
			printf("Error.\n");
				return -1;
		}
		
		printf("%2d %2d %2d %2d\r\n", ty[0], ty[1], ty[2], ty[3]);

		result = ty[i] * pow(16, g) + result;
		g--;
	}
	return result;
}

