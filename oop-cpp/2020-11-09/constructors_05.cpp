#include <iostream>

class Foo {

public:
    int a;

    Foo() : a(1) {
        std::cout << "Constructor called" << std::endl;
    }

    Foo(const Foo& source) {
        this->a = source.a * 2;

        std::cout << "Copy constructor called" << std::endl;
    }
};

void print(Foo foo) {
    std::cout << foo.a << std::endl;
}

int main() {
    Foo foo;

    std::cout << foo.a << std::endl;
    print(foo);

    return 0;
}