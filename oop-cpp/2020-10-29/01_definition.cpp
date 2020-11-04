#include <iostream>

using namespace std;

class Point {
    // not OK!
    // int a = 1;
    float x;
    float y;
public:
    void setX(float x);
    float getX() {
        return this->x;
    }
};

void Point::setX(float x) { this->x = x; };

int main() {
    Point p;

    p.setX(2);
    cout << p.getX() << endl;
}
