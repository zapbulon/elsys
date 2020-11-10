#include <iostream>

using namespace std;

class Foo {
    int a;

    friend ostream& operator<<(ostream& out, const Foo& foo);
public:
    Foo() : a(2) {}
};

ostream& operator<<(ostream& out, const Foo& foo) {
    out << "Foo:" << foo.a;
    return out;
}

int main() {
    Foo a;

    cout << a << endl;
}