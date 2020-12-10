#include <iostream>
#include "Drawing.hpp"

using namespace std;

void Drawing::add(const Shape* shape) {
    shapes_.push_back(shape);
}

void Drawing::print(void) const {
    cout << "Drawing{" << endl;

    for (list<const Shape*>::const_iterator it = shapes_.begin(); it != shapes_.end(); ++it) {
        cout << "\t";
        (*it)->print();
    }

    cout << "}" << endl;
}
