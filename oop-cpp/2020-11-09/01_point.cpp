#include <iostream>

using namespace std;

class Point {
    double x_ , y_ ;
public :
    Point (double x=0, double y=0)
        : x_(x) , y_(y) {}

    double get_x() const { return x_; }
    double get_y() const { return y_; }

    Point& add(const Point& p);
    Point& sub(const Point& p);
    Point& mul(double a);
};

Point& Point::add(const Point& p) {
    x_ += p.x_;
    y_ += p.y_;
    return *this;
}

Point& Point::sub(const Point& p) {
    x_ -= p.x_;
    y_ -= p.y_;
    return *this;
}

Point& Point::mul(double a) {
    x_ *= a;
    y_ *= a;
    return *this;
}

int main() {
    Point p1(1.0, 1.0);
    Point p2(2.0, 2.0);
    Point p3(3.0, 3.0);

    p3.add(p2).sub(p1).mul(10.0);

    cout << "(" << p3.get_x() << ", " << p3.get_y() << ")" << endl;
}