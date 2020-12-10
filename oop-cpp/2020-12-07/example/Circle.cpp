#include <iostream>
#include "Circle.hpp"

using namespace std;

Circle::Circle(const Point& center, double radius)
    : center_(center), radius_(radius) {}

void Circle::print(void) const {
    cout << " Circle(";
    center_.print();
    cout << ", " << radius_ << ")" << endl;
}
