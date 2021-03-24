#include <iostream>

using namespace std;

class A {
public:
    void test() {
        this->print();
    }

    virtual void print() {
        cout << "A" << endl;
    }
};

class B : public A {
    void print() {
        cout << "B" << endl;
    }
};

int main() {
    B instance;

    instance.test();

    return 0;
}
