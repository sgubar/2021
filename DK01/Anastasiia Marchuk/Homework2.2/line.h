#ifndef line_h
#define line_h

#include <stdio.h>

// Point description
typedef struct tagPoint
{
	int x;
	int y;
}Point;

// Line description
typedef struct tagLine
{
	Point *A;
	Point *B;
  Point *C;
}Line;

// Init interface
Line *createLine(Point *A, Point *B);
Line *createLineWithCoordinate(int xA, int yA, int xB, int yB);
void destroyLine(Line *aLine);

float lenghLine(Line *aLine);
void printLine(Line *aLine);

//////////////////////////////////////////////////
Line *createLine(Point *B, Point *C);
Line *createLineWithCoordinate(int xB, int yB, int xC, int yC);
void destroyLine(Line *bLine);

float lenghLine(Line *bLine);
void printLine(Line *bLine);

///////////////////////////////////////////////////
Line *createLine(Point *C, Point *A);
Line *createLineWithCoordinate(int xC, int yC, int xA, int yA);
void destroyLine(Line *cLine);

float lenghLine(Line *cLine);
void printLine(Line *cLine);

#endif
