#include "Drawing.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Point.hpp"

int main(void) {
    Rectangle r1(Point(0, 0), Point(10, 10));
    Circle c1(Point(0, 0), 10), c2(Point(10, 10), 10);

    Drawing d1;
    d1.add(& r1);
    d1.add(& c1);
    d1.add(& c2);
    d1.print();

    return 0;
}