#ifndef CIRCLE_HPP__
#define CIRCLE_HPP__

#include "Point.hpp"
#include "Shape.hpp"

class Circle: public Shape {
    Point center_;
    double radius_;
public:
    Circle(const Point& center, double radius);
    void print(void) const;
};

#endif