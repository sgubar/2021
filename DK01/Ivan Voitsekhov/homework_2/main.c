#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
struct Point
{
    double x, y;
};
struct Rectangle
{
    Point* mass;
    double side1, side2, area;
    void CountSides() {
        side1 = pow(pow(mass[1].x - mass[0].x, 2) + pow(mass[1].y - mass[0].y, 2), 0.5);
        side2 = pow(pow(mass[3].x - mass[0].x, 2) + pow(mass[3].y - mass[0].y, 2), 0.5);
    }
    void CountArea() {
        area = side1 * side2;
    }
};
Rectangle* CreateRectangle(Point mass[4]) {
    Rectangle* rectangle =  new Rectangle;
    rectangle->mass = mass;
    rectangle->CountSides();
    rectangle->CountArea();
    return rectangle;
}
void PrintRectangle(Rectangle* rect) {
    printf("\n\nFirst side = %f. Second side = %f.\nArea = %f",rect->side1, rect->side2, rect->area);
}
void Delete(Rectangle* rect) {
    rect->mass = nullptr;
}
int main()
{
    Point points[4];
    points[0].x = 1;
    points[0].y = 1.1;
    points[1].x = 2.5;
    points[1].y = 3;
    points[2].x = 5;
    points[2].y = 8;
    points[3].x = 8;
    points[3].y = 15;
    Rectangle* rect = CreateRectangle(points);
    PrintRectangle(rect);
    printf("\n\n");
  
}
