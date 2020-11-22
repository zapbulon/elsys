#include <iostream>

using namespace std;

class Foo {
public:
    int* array;

    Foo(int size) {
        this->array = new int[size];
    }

    ~Foo() {
        delete [] this->array;
    }
};

int main() {
    Foo foo(2);

    foo.array[0] = 3;
    foo.array[1] = 6;

    cout << foo.array[1] << endl;

    return 0;
}