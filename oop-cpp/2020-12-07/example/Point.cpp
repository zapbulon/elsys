#include <iostream>
#include "Point.hpp"

using namespace std;

void Point::print(void) const {
    cout << "(" << x_ << ", " << y_ << ")";
}

