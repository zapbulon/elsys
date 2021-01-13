#include <iostream>

using namespace std;

/*
    The diamond problem

    Without virtual:

      A   A
      |   |
     B1   B2
      \   /
        C

*/

class A {
public:
    int a;
};

class B1 : virtual public A {
public:
    int b1;

    int getA() {
        return this->a;
    }
};

class B2 : virtual public A {
public:
    int b2;
};

class C : public B1, public B2 {
public:
    int c;
};

int main() {
    C instance;

    instance.B1::a = 1;

    cout << "B1::a = " << instance.B1::a << endl;
    cout << "B2::a = " << instance.B2::a << endl;

    B1 b1;
    b1.b1 = 4;

    cout << b1.b1;

    return 0;
}