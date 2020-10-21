#include <iostream>

template <class T> void add(T a, T b) {
    std::cout << a+b << std::endl;
};

int main() {
    add<int>(1, 2); 
    add<double>(1.2, 2.85);

    return 0;
}