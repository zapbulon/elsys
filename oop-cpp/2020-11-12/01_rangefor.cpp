#include <iostream>

using namespace std;

int main() {
    char chars[3] = {'a', 'b', 'c'};

    for (int i = 0; i < 3; i++) {
        cout << chars[i] << endl;
    }

    for (char c : chars) {
        cout << c << endl;
    }
}