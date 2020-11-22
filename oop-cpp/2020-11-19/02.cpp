#include <iostream>

using namespace std;

class Foo {
    public: short a;

    Foo(int a) {
        this->a = a;
        cout << "Constructor called!" << endl;
    }

    Foo(const Foo& source) {
        this->a = source.a;

        cout << "Copy constructor called!" << endl;
    }
};

Foo* doubleFoo(int a) {
    Foo* f = new Foo(a * 2);

    cout << "In doubleFoo" << endl;

    return f;
}

int main() {
    Foo* f = doubleFoo(8);

    cout << f->a << endl;

    delete f;

    cout << f->a << endl;

    return 0;
}