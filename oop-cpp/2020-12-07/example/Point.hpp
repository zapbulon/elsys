#ifndef POINT_HPP__
#define POINT_HPP__

class Point {
    double x_ , y_;
public :
    Point(double x = 0.0, double y = 0.0)
        : x_(x) , y_(y) {}

    double get_x(void) const { return x_; }
    double get_y(void) const { return y_; }

    Point& set_x(double x) {
        x_ = x;
        return *this;
    }

    Point& set_y(double y) {
        y_ = y;
        return *this;
    }

    void print(void) const;
};

#endif