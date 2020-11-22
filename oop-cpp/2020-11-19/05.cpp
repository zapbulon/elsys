#include <iostream>

using namespace std;

class Foo {
public:
    int* array;

    Foo(int size) {
        this->array = new int[size];
    }
};

int main() {

    Foo foo(2);

    foo.array[0] = 12;
    foo.array[1] = 24;

    cout << *foo.array << endl;
    cout << *(foo.array+1) << endl;

    delete[] foo.array;

    cout << *foo.array << endl;
    cout << *(foo.array+1) << endl;

    return 0;
}