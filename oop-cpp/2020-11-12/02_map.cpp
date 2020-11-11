#include <iostream>
#include <map>
#include <utility>

using namespace std;

class Foo {
public:
    int a;
    Foo() {}
    Foo(int b) : a(b % 3) {}
};

ostream& operator<<(ostream& out, const Foo& foo) {
    out << "Foo(" << foo.a << ")";

    return out;
}

// https://en.cppreference.com/w/cpp/container/map
// std::map is a sorted associative container that contains key-value pairs with unique keys

int main() {
    map<char, Foo> foo;

    foo['c'] = Foo(3);
    foo.insert({'a', Foo(2)});
    foo['b'] = Foo(7);

    for (auto element : foo) {
        cout << element.first << ": " << element.second << endl;
    }

    pair<int, char> p = {2, 'b'};
    cout << endl << p.first << ": " << p.second << endl;
}