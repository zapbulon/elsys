#include <iostream>

using namespace std;

class Scopes {
    // this here is private
    int a;    
private:
    int b;
public:
    int c;
protected:
    int d;
};

int main() {

    Scopes showcase;

    // error: ‘int Scopes::a’ is private within this context
    showcase.a = 1;
    // error: ‘int Scopes::b’ is private within this context
    showcase.b = 2;
    // all cool!
    showcase.c = 3;
    // error: ‘int Scopes::d’ is private within this context
    showcase.d = 4;

    return 0;
}
