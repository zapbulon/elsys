#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<class T>
T square(T t) {
    return t * t;
}

template<class T>
class Human {
public:
    T height;
    Human(T h) : height(h) {}

    Human operator*(Human& h) {
        return Human(h.height * this->height);
    }
};

int main() {
    cout << square<int>(2) << " " << square<float>(1.5) << endl
         << (square<Human<float>>(Human<float>(1.9))).height << endl;

    return 0;
}