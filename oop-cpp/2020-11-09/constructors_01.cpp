#include <iostream>

class Woo {
public:
    int a;
    Woo() {
        a = 10;
    }
};

class Foo {
public:
    Woo woo;
};

int main() {
    Foo foo;

    std::cout << foo.woo.a << std::endl;

    return 0;
}