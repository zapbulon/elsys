#include <iostream>
#include "Rectangle.hpp"

using namespace std;

Rectangle::Rectangle(const Point& ul, const Point& br)
    : ul_(ul), br_(br) {}

void Rectangle::print(void) const {
    cout << " Rectangle(";
    ul_.print();
    cout << ", ";
    br_.print();
    cout << ")" << endl;
}
