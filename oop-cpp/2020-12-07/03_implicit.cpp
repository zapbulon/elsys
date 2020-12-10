#include <iostream>

using namespace std;

class Test {
    string s;
    int i;
public:
    explicit Test(string s) : s(s) {}
    Test(int i) : i(i) {}

    friend ostream& operator<<(ostream& out, const Test& test);
};

ostream& operator<<(ostream& out, const Test& test) {
    out << "string(" << test.s << "); int(" << test.i << ")";

    return out;
}

int main() {

    cout << t << endl;

    return 0;
}