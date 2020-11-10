#include <iostream>

class Foo {

public:
    int a;
    int b;

    Foo() : a(1), b(2) {}
};

int main() {
    Foo foo;

    std::cout << foo.a << " " << foo.b << std::endl;

    return 0;
}