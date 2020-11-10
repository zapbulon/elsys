#include <iostream>
#include <vector>

using namespace std;

class Student {
    static int instances;

    short position;
    string name;
public:
    Student(string name) {
        this->name = name;
        this->position = (this->instances % 2) + 1;
        this->instances++;
    }

    void reportPosition() {
        cout << position << '!' << endl;
    }

    void reportState() {
        cout << "I'm " << this->name << " and there is " << this->instances << " of us" << endl;
    }
};

int Student::instances = 0;

int main() {
    Student s1 = Student("John");
    Student s2 = Student("George");
    Student s3 = Student("Bill");

    s1.reportPosition(); // 1!
    s2.reportPosition(); // 2!
    s3.reportPosition(); // 1!

    s3.reportState(); // I' m Bill and there is 3 of us
}