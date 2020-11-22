#include <iostream>
#include <map>

using namespace std;

class Weapon {
    int* uses;

    static int instances;
public:

    Weapon(string type) {
        instances++;

        int actions = type == "pistol" ? 1 : 2;

        this->uses = new int[actions];
    }

    ~Weapon() {
        instances--;

        delete[] this->uses;
    }

    static int currentInstances() {
        cout << "Current instances: " << instances << endl;
    }
};

int Weapon::instances = 0;

int main() {
    Weapon pistol = Weapon("pistol");

    {
        Weapon shotgun = Weapon("shotgun");

        Weapon::currentInstances();
    }

    Weapon::currentInstances();

    return 0;
}