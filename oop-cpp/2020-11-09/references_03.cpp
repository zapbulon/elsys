#include <iostream>
#include <vector>

using namespace std;

class Foo {
public:
    short a;
    short b;

    Foo& setA(short a) {
        this->a = a;

        return *this;
    }

    void setB(short b) {
        this->b = b;
    }
};

int main() {
    Foo foo;

    foo.setA(1).setB(2);

    cout << foo.a << " " << foo.b << endl;
}