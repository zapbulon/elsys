#include <iostream>
#include <sstream>

using namespace std;

int main() {
    stringstream test;
    int a;
    string str;

    test << " haha\t123";
    test >> str;
    cout << "We've just extracted: " << str << endl;

    test << "10";
    test >> a;

    cout << "The value of 'a' is: " << a << endl;
    return 0;
}


