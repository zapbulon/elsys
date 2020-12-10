#ifndef RECTANGLE_HPP__
#define RECTANGLE_HPP__

#include "Point.hpp"
#include "Shape.hpp"

class Rectangle: public Shape {
    Point ul_;
    Point br_;
public:
    Rectangle(const Point& ul, const Point& br);
    void print(void) const;
};

#endif