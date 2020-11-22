#include <iostream>

using namespace std;

class Foo { short a; };

struct Boo { long a; };

int main() {

    int a;
    Foo f;
    Boo b;

    // sizeof returns size in bytes

    cout << "size a: " << sizeof(a) << endl;
    cout << "size f: " << sizeof(f) << endl;
    cout << "size b: " << sizeof(b) << endl;

    return 0;
}