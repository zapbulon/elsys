#include <iostream>

class Woo{

};

class Foo {

public:
    int a;

    Woo* w;

    Foo() : a(1) {
        std::cout << "Constructor called" << std::endl;
    }

    Foo(const Foo& source) {
        this->a = source.a;

        std::cout << "Copy constructor called" << std::endl;
    }

    Foo& operator=(const Foo& source) {
        std::cout << "operator= called" << std::endl;

        return *this;
    }
};

void print(Foo foo) {

}

int main() {
    // Constructor called
    Foo foo;

    // Copy constructor called
    print(foo);

    // Copy constructor called
    Foo foo2 = foo;

    // operator= called
    foo2 = foo;

    return 0;
}