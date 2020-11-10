#include <iostream>
#include <vector>

using namespace std;

class Foo {
public:
    short a;
    short b;

    void setA(short a) {
        this->a = a;
    }

    void setB(short b) {
        this->b = b;
    }
};

int main() {
    Foo foo;

    foo.setA(1);
    foo.setB(2);

    cout << foo.a << " " << foo.b << endl;
}