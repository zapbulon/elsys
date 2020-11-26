#include <iostream>

using namespace std;

class Set;

class Container {
    string model;
    string type;
    string serialNumber;

    int capacity;
public:
    Container() {
        cout << "Container constructed - default" << endl;
    }

    Container(string model, int capacity, string type, string serialNumber)
        : model(model), capacity(capacity), type(type), serialNumber(serialNumber) {
        cout << "Container constructed" << endl;
    }

    Container(const Container& c) {
        cout << "Container copied" << endl;
    }

    void print() {
        cout << model << " " << type << " " << capacity
             << "gr container. Serial number: " << serialNumber << endl;
    }

    friend Set;
    friend Set* operator+(const Container& first, const Container& second);
};

class Set {
    // Why const? Because I wanna illustrate that when a set is created
    // it is sealed and you can't change the containers
    const Container* salt;
    const Container* pepper;

    string serialNumber;
public:
    Set() {
        cout << "Set constructed - default" << endl;
    }

    Set(const Container* salt, const Container* pepper)
        : salt(salt), pepper(pepper), serialNumber(salt->serialNumber + ':' + pepper->serialNumber) {
        cout << "Set constructed" << endl;
    }

    Set(const Set& c) {
        cout << "Set copied" << endl;
    }

    void print() {
        cout << this->salt->model << " set with serial number: " << this->serialNumber << endl;
    }
};

class Model {
    string name;
    int capacity;

    // My intial solution was with non-static variable so
    // every model keeps track of serial numbers separately
    // but the solution we wrote in class was with static
    static int serialNumber;
public:
    Model(string name, int capacity)
        : name(name), capacity(capacity) {
            cout << "Model constructed" << endl;
    }

    static Container* produce(Model& model, string type) {
        // Yes, you can use ENUM for type. Yes, you should check the type.
        return new Container(model.name, model.capacity, type, to_string(Model::serialNumber++));
    }
};

int Model::serialNumber = 1000;

Set* operator+(const Container& first, const Container& second) {
    if (first.type == second.type) {
        throw "a set should have different container types";
    }

    if (first.model != second.model) {
        throw "a set should have containers of the same model";
    }

    return new Set(
        first.type == "salt" ? &first : &second,
        first.type == "salt" ? &second : &first
    );
}

int main() {
    Model model = Model("California", 60);

    Container* salt = Model::produce(model, "salt");
    Container* pepper = Model::produce(model, "pepper");

    salt->print();
    pepper->print();

    Set* set = *salt + *pepper;

    set->print();

    delete salt, pepper, set;

    return 0;
}