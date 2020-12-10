#ifndef DRAWING_HPP__
#define DRAWING_HPP__

#include <list>
#include "Shape.hpp"
using namespace std;

class Drawing {
    list <const Shape*> shapes_;
public :
    void add(const Shape* shape);
    void print(void) const;
};

#endif