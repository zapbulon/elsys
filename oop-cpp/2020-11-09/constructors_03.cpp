#include <iostream>

class Foo {

public:
    int a;
    int b;

    Foo(int x, int y) : a(x+1), b(y+2) {}
};

int main() {
    Foo foo = Foo(1, 2);

    std::cout << foo.a << " " << foo.b << std::endl;

    return 0;
}