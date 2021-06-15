#include <iostream>
#include <fstream>
#include <ctime>

#define Q_ANDLES 3

struct Point
{
    double X;
    double Y;
};

double segmentLength(const Point* first, const Point* second)
{
    return sqrt(pow(second->X - first->X, 2) + pow(second->Y - first->Y, 2));
}

struct RightTriangle
{
    Point m_Points[Q_ANDLES];
};

bool isRightTriangle(const Point* A, const Point* B, const Point* C)
{
    double aSide = segmentLength(A, B);
    double bSide = segmentLength(B, C);
    double cSide = segmentLength(C, A);

    if (pow(aSide, 2) == pow(bSide, 2) + pow(cSide, 2)) return true;
    else if (pow(bSide, 2) == pow(aSide, 2) + pow(cSide, 2)) return true;
    else if (pow(cSide, 2) == pow(aSide, 2) + pow(bSide, 2)) return true;
    else return false;
}


RightTriangle* createTriangle(const Point* APoint, const Point* BPoint, const Point* CPoint)
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

RightTriangle* createTriangle(const Point* otherPoints)
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

struct Array
{
    RightTriangle** m_Triangles;
    int m_iSize;
};

Array createArray(const int N = 0)
{
    Array arr;
    arr.m_iSize = 0;
    arr.m_Triangles = nullptr;
    if (N > 0)
    {
        arr.m_Triangles = new RightTriangle *[N];
        for (size_t i = 0; i < N; i++)
        {
            arr.m_Triangles[i] = nullptr;
        }
        arr.m_iSize = N;
    }
    return arr;
}

void deleteArray(Array& otherArray)
{
    for (size_t i = 0; i < otherArray.m_iSize; i++)
    {
        if (otherArray.m_Triangles[i])
        {
            delete otherArray.m_Triangles[i];
        }
    }
    delete[] otherArray.m_Triangles;
    otherArray = createArray(0);
    otherArray.m_iSize = 0;
}

int addToArray(Array& otherArray, RightTriangle& otherTriangle)
{
    RightTriangle** newArray = new RightTriangle *[otherArray.m_iSize + 1];
    for (size_t i = 0; i < otherArray.m_iSize; i++)
    {
        newArray[i] = otherArray.m_Triangles[i];
    }
    newArray[otherArray.m_iSize] = createTriangle(otherTriangle.m_Points);
    delete[] otherArray.m_Triangles;
    otherArray.m_Triangles = newArray;
    otherArray.m_iSize++;
    return otherArray.m_iSize - 1;
}

int insertByIndex(Array& otherArray, RightTriangle& otherTriangle, int index)
{
    if (index >= 0 && index < otherArray.m_iSize)
    {
        if (otherArray.m_Triangles[index])
        {
            delete otherArray.m_Triangles[index];
        }
        otherArray.m_Triangles[index] = createTriangle(otherTriangle.m_Points);
        return index;
    }
    else
    {
        return -1;
    }
}

void printArray(Array& otherArray)
{
    for (size_t i = 0; i < otherArray.m_iSize; i++)
    {
        std::cout << i + 1 << " triangle --> ";
        PrintRightTriangle(otherArray.m_Triangles[i]);
        std::cout << std::endl;
    }
}

int main()
{
    Point APoint;
    APoint.X = 1;
    APoint.Y = 1;

    Point BPoint;
    BPoint.X = 1;
    BPoint.Y = 6;

    Point CPoint;
    CPoint.X = 4;
    CPoint.Y = 1;

    Array arr = createArray(3);

    for (size_t i = 0; i < arr.m_iSize; i++)
    {
        insertByIndex(arr, *createTriangle(&APoint, &BPoint, &CPoint), i);
        APoint.X++;
        BPoint.X++;
        CPoint.X++;
    }

    addToArray(arr, *createTriangle(&APoint, &BPoint, &CPoint));

    printArray(arr);

    if (insertByIndex(arr, *createTriangle(&APoint, &BPoint, &CPoint), 10) == -1)
    {
        std::cout << "\nInsert is imposible." << std::endl;
    }

    deleteArray(arr);
    return 0;
}
