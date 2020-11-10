#include <iostream>
#include <vector>

using namespace std;

class Student {
    short age;
    string name;

    const static short drinkingAge = 18;
public:
    Student(string name, short age) {
        this->name = name;
        this->age = age;
    }

    Student(const Student& source) {
        this->name = source.name;
        this->age = source.age;

        std::cout << "Copy constructor called" << std::endl;
    }

    static const Student& elect(const Student& a, const Student& b) {
        return a.age > b.age ? a : b;
    }

    void buyBeer() const {
        cout << "I'm " << this->name << ", I'll try to get the beer as I'm older ..." << endl;

        if (this->age >= this->drinkingAge) {
            cout << "Woho, I got it!" << endl;
        } else {
            cout << "Lame, I'm still underaged :(" << endl;
        }
    }
};

int main() {
    Student s1 = Student("John", 17);
    Student s2 = Student("George", 18);
    Student s3 = Student("Brian", 16);

    Student::elect(s1, s3).buyBeer();
    // outputs:
    // I'm John, I'll try to get the beer as I'm older ...
    // Lame, I'm still underaged :(

    Student::elect(s1, s2).buyBeer();
    // outputs:
    // I'm George, I'll try to get the beer as I'm older ...
    // Woho, I got it!
}