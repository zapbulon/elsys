#include "tmpl-stack.hpp"

int main(void) {
    stack<int> si;

    cout << "Let's play with a stack of ints!" << endl;
    for (int i=0; i<10; ++i) {
        si.push(i);
    }

    while (!si.empty()) {
        cout << si.top() << " ";
        si.pop();
    }

    cout << endl << endl << "Let's play with a stack of floats!" << endl;

    stack<float> sf;

    for (int i=1; i<10; ++i) {
        sf.push(i * 3.14);
    }

    while (!sf.empty()) {
        cout << sf.top() << " ";
        sf.pop();
    }

    cout << endl;
}