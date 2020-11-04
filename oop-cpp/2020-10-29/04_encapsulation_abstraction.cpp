#include <iostream>

using namespace std;

// https://www.tutorialspoint.com/cplusplus/cpp_data_encapsulation.htm :
// Encapsulation is an Object Oriented Programming concept that binds 
// together the data and functions that manipulate the data, and that 
// keeps both safe from outside interference and misuse. 
// Data encapsulation led to the important OOP concept of data hiding.
// 
// Data encapsulation is a mechanism of bundling the data, and the functions 
// that use them and data abstraction is a mechanism of exposing only the 
// interfaces and hiding the implementation details from the user.
class Person {
    string firstName;
    string tussenvoegsel; // https://en.wikipedia.org/wiki/Tussenvoegsel
    string lastName;
public:
    Person(string firstName, string tussenvoegsel, string lastName) {
        this->firstName = firstName;
        this->tussenvoegsel = tussenvoegsel;
        this->lastName = lastName;
    }

    string name() {
        return this->firstName + " " + this->tussenvoegsel + " " + this->lastName;
    }

    string familyName() {
        string tv = this->tussenvoegsel;
        tv[0] = toupper(tv[0]);

        return tv + " " + this->lastName;
    }
};

int main() {
    Person dutchGuy = Person("Donny", "van de", "Beek");

    // Encapsulation: we don't allow you to directly access the name properties
    // so we can store them in a normalized form - e.g. we may convert all 
    // characters of the tussenvoegsel to lower in the constructor

    // Abstraction: we provide an interface for you to access the name. There is
    // a rule with Dutch names - the tussenvoegsel is written with a capital 
    // first letter when the first name is not present and it's written lowercase
    // when the first name is specified. So - have a look at the following example:
    cout << dutchGuy.name() << endl;        // Donny van de Beek
    cout << dutchGuy.familyName() << endl;  // Van de Beek

    // ^ the user does not need to know about this name priniting logic and should
    // not care. All they need to know is they can access the name via our methods 

    return 0;
}

