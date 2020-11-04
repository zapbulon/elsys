#include <iostream>

using namespace std;

class Point {
    float x;
    float y;
public:
    Point() : x(0), y(0) {}
    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void print() {
        cout << x << "x" << y << endl;
    } 
};

int main() {

    {
        Point p1;               p1.print(); // 0x0
        Point p2 = Point();     p2.print(); // 0x0
        Point p3{};             p3.print(); // 0x0
        Point p4 = {};          p4.print(); // 0x0
    }
    
    {
        Point p1(1, 2);         p1.print(); // 1x2
        Point p2 = Point(1, 2); p2.print(); // 1x2
        Point p3{2, 1};         p3.print(); // 2x1
        Point p4 = Point{2, 1}; p4.print(); // 2x1
    }

    return 0;
}
