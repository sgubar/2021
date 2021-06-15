#include <iostream>
#include <fstream>
#include <ctime>

#define Q_ANDLES 3

struct Point
{
    double X;
    double Y;
};

double segmentLength(Point* first, Point* second)
{
    return sqrt(pow(second->X - first->X, 2) + pow(second->Y - first->Y, 2));
}

struct RightTriangle
{
    Point m_Points[Q_ANDLES];
};

bool isRightTriangle(Point* A, Point* B, Point* C)
{
    double aSide = segmentLength(A, B);
    double bSide = segmentLength(B, C);
    double cSide = segmentLength(C, A);

    if (pow(aSide, 2) == pow(bSide, 2) + pow(cSide, 2)) return true;
    else if (pow(bSide, 2) == pow(aSide, 2) + pow(cSide, 2)) return true;
    else if (pow(cSide, 2) == pow(aSide, 2) + pow(bSide, 2)) return true;
    else return false;
}


RightTriangle* createTriangle(Point* APoint, Point* BPoint, Point* CPoint)
{
    if (isRightTriangle(APoint, BPoint, CPoint))
    {
        RightTriangle* tr = new RightTriangle;
        tr->m_Points[0] = *APoint;
        tr->m_Points[1] = *BPoint;
        tr->m_Points[2] = *CPoint;
        return tr;
    }
    else
    {
        return nullptr;
    }
}

RightTriangle* createTriangle(Point* otherPoints)
{
    return createTriangle(&otherPoints[0], &otherPoints[1], &otherPoints[2]);
}

RightTriangle* createTriangle(double APointX, double APointY, double BPointX, double BPointY, double CPointX, double CPointY)
{
    Point APoint;
    APoint.X = APointX;
    APoint.Y = APointY;

    Point BPoint;
    BPoint.X = BPointX;
    BPoint.Y = BPointY;

    Point CPoint;
    CPoint.X = CPointX;
    CPoint.Y = CPointY;
    
    return createTriangle(&APoint, &BPoint, &CPoint);
}


void PrintRightTriangle(const RightTriangle* otherTriangle)
{
    char pointName = 'A';
    for (size_t i = 0; i < Q_ANDLES; i++)
    {
        std::cout << pointName++ << "(" << otherTriangle->m_Points[i].X << ", " << otherTriangle->m_Points[i].Y << ")\t";
    }
}


int main()
{
    
    const int qTriangles = 3;
    RightTriangle** arrTriangles = new RightTriangle*[qTriangles];

    Point APoint;
    APoint.X = 1;
    APoint.Y = 1;

    Point BPoint;
    BPoint.X = 1;
    BPoint.Y = 6;

    Point CPoint;
    CPoint.X = 4;
    CPoint.Y = 1;

    Point points[Q_ANDLES] = { APoint, BPoint, CPoint };
    arrTriangles[0] = createTriangle(points);

    APoint.X++;
    BPoint.X++;
    CPoint.X++;
    arrTriangles[1] = createTriangle(&APoint, &BPoint, &CPoint);

    arrTriangles[2] = createTriangle(3, 1, 3, 6, 6, 1);

    for (size_t i = 0; i < qTriangles; i++)
    {
        std::cout << i + 1 << " triangle --> ";
        PrintRightTriangle(arrTriangles[i]);
        std::cout << std::endl;
    }

    for (size_t i = 0; i < qTriangles; i++)
    {
        delete arrTriangles[i];
    }
    delete[] arrTriangles;

    return 0;
}
