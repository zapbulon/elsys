#include <iostream>

using namespace std;

class Test {
    static int instances;
public:
    Test() {
        instances++;
    }

    static void print() {
        cout << "Instances: " << instances << endl;
    }
};

int Test::instances = 0;

int main() {
    Test x;
    Test y;

    Test::print();
}