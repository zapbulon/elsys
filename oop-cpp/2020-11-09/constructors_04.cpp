#include <iostream>

class Foo {

public:
    int a;

    Foo() : a(1) { }
};

int main() {
    Foo f1;

    Foo f2 = f1;
    std::cout << f1.a << " " << f2.a << std::endl;

    f1.a = 2;
    std::cout << f1.a << " " << f2.a << std::endl;

    return 0;
}