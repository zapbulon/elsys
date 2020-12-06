#include <iostream>

using namespace std;

class Employee {
    string name;
    long id;
public:
    Employee(string name, long id)
        : name(name), id(id) {}

    string getName() const {
        return this->name;
    }

    long getId() const {
        return this->id;
    }
};

class Manager : public Employee {
    int level;
public:
    Manager(string name, long id, int level)
        : Employee(name, id), level(level) {}

    int getLevel() const {
        return this->level;
    }

    string getName() const {
        return "Manager: " + Employee::getName();
    }
};

/*
Upcasting is converting a derived-class reference or pointer to a base-class.
In other words, upcasting allows us to treat a derived type as though it were
its base type. It is always allowed for public inheritance, without an explicit
type cast. This is a result of the is-a relationship between the base and derived classes.
*/
void print(Employee& e) {
    cout << e.getName() << endl;
}

int main() {
    Manager manager = Manager("Big Boss", 1, 1);

    print(manager);
}