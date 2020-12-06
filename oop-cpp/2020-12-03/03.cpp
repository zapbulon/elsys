#include <iostream>

using namespace std;

class Employee {
    string name; long id;
public:
    Employee(string name, long id)
        : name(name), id(id) {}

    virtual string getName() const { return this->name; }
    long getId() const { return this->id; }
};

class Manager : public Employee {
    int level;
public:
    Manager(string name, long id, int level)
        : Employee(name, id), level(level) {}

    int getLevel() const { return this->level; }
    string getName() const { return "Manager: " + Employee::getName(); }
};

void print(Employee& e) {
    cout << e.getName() << endl;
}

int main() {
    Manager manager = Manager("Big Boss", 1, 1);
    print(manager);
}