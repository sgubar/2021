#include "circle.h"

PCircle makeCircle(PLine l1)
{
	double radius1 = lenghtLine(l1);
	if (l1 == NULL)
	{
		return;
	}
	if (radius1 <= 0)
	{
		printf("\nThe radius is 0 or less");
		return;
	}
	PCircle c = (PCircle)malloc(sizeof(PCircle));
	if (c != NULL)
	{
		c->l = l1;
		c->radius = radius1;
	}
	return c;
}
void printCircle(PCircle c)
{
	if (c == NULL)
	{
		return;
	}
	printf("\nThe circle Center is: ");
	printPoint(c->l->A);
	printf("\nThe second point is: ");
	printPoint(c->l->B);
	printf("\nCircle radius is: %d", lenghtLine(c->l));
	printf("\nCircle square is: %d", sqCircle(c));
}
double sqCircle(PCircle c)
{
	if (c != NULL)
	{
		double sq = (22 / 7)*(c->radius)* (c->radius);
		return sq;
	}
	return -1;
}
void deleteCircle(PCircle c)
{
	if (c != NULL)
	{
		deletePoint(c->l->A);
		deletePoint(c->l->B);
		deleteLine(c->l);
		free(c);
	}
}