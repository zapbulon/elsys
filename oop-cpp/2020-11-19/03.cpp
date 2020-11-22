#include <iostream>

using namespace std;

class Foo {
public:
    int a;
    Foo() {}
    Foo(int a) : a(a * 10){}
};

int main() {
    Foo* ptr1 = new Foo;
    Foo* ptr2 = new Foo(21);
    Foo* arr1 = new Foo[10];

    cout << "Values:" << endl;

    arr1[0].a = 1;
    arr1[1].a = 2;

    cout << "ptr1->a: " << ptr1->a << endl;
    cout << "ptr2->a: " << ptr2->a << endl;
    cout << "arr1->a: " << (arr1)->a << endl;

    cout << endl << "Pointer sizes: " << endl;

    cout << "ptr1->a: " << sizeof(ptr1) << endl;
    cout << "ptr2->a: " << sizeof(ptr2) << endl;
    cout << "arr1->a: " << sizeof(arr1) << endl;

    cout << endl << "Object sizes: " << endl;

    cout << "ptr1->a: " << sizeof(*ptr1) << endl;
    cout << "ptr2->a: " << sizeof(*ptr2) << endl;
    cout << "arr1->a: " << sizeof(*arr1) << endl;

    return 0;
}