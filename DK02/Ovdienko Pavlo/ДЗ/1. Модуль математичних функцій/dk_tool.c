#include "dk_tool.h"

int arr_out[5], result, n;

int just(char* ty)
{
	for (int i = 0; i <= 4; i++)
	{
		if ((ty[i] == 10))
		{
			n = i;
		}
		if ((int)ty[i] >= 65 && (int)ty[i] <= 70)
		{
			arr_out[i] = (int)ty[i] - 55;
		}
		else if ((int)ty[i] >= 97 && (int)ty[i] <= 102)
		{
			arr_out[i] = (int)ty[i] - 87;
		}
		else if ((int)ty[i] >= 48 && (int)ty[i] <= 57)
		{
			arr_out[i] = ty[i] - 48;
		}
	}

	switch (n)
	{
	case 1:
		result = arr_out[0];
		break;
	case 2:
		result = arr_out[0] * 16 + arr_out[1] * 1;
		break;
	case 3:
		result = arr_out[0] * (16 * 16) + arr_out[1] * 16 + arr_out[2] * 1;
		break;
	case 0:
		result = arr_out[0] * (16 * 16 * 16) + arr_out[1] * (16 * 16) + arr_out[2] * 16 + arr_out[3] * 1;
		break;
	}
	return result;
}