#include "arrays.h"

PArray makeArray(int amount1)
{
	PArray arC = (PArray)malloc(sizeof(Array));
	if (NULL != arC)
	{
		arC->amount = (amount1 > 0) ? amount1 : 1;
		arC->c = (PCircle*)calloc(arC->amount, sizeof(PCircle) * arC->amount);
	}
	return arC;
}
void setCircleAtIndex(PArray s1, PCircle c1, int index)
{

}
PCircle getCircleAtIndex(PArray s1, int index)
{

}
void deleteArray(PArray s1)
{

}
void printArrayCircles(PArray a)
{

}