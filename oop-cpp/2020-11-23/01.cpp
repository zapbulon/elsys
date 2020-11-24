#include <iostream>

using namespace std;

class Vehicle {
public:
    // this is the first time I'm showing you a custom type (enum, but could be class also)
    // defined within a class. Notice it is in a public section so it is visible
    // outside the class. To access types defined this way outside of the class (e.g. in main())
    // we use the "scope resolution operator", or as we know it :: (two colons)
    // https://www.tutorialspoint.com/Scope-resolution-operator-in-Cplusplus
    //
    // We've already seen it when we use static functions - check main() below, we have:
    //      Vehicle::factory(/* ... */)
    //
    // The same operator we use with namespaces:
    //      std::cout
    //
    // The same operator we used with itarators:
    //      vector<int>::iterator
    //
    // the scope resolution operator should always make us think we're using a thing
    // that is contained by something else

    enum TwoAxleDrives { FRONT, REAR, ALL, NONE };
    enum TwoAxleVehicles { BIKE, CAR, TRAILER };
private:

    // now that we have defined a custom variable type with enum - we can use it as any
    // other type, e.g:
    //      int i;
    //      float f;
    //      std::string s;
    //      vector<int>::iterator it;
    //
    // The structure is always the same
    //      TYPE VARIABLE_NAME;
    //          or with an initial value (not in a class definition):
    //      TYPE VARIABLE_NAME = VALUE;

    TwoAxleVehicles type;
    TwoAxleDrives drive;

    float km;

// this is actually a second public section! Totally allowed as many times you want!
public:
    // default constructor
    // after the ":" and before the function body "{}" we can initialize (give value to)
    // class variables with the syntax:
    //      CLASS_VARIABLE_NAME(VALUE)
    //
    // so in the example below we init
    //      this->km = 0
    // it is the exact same equivalent to
    //      Vehicle() { this->km = 0; }
    Vehicle() : km(0) {}

    // TwoAxleVehicles & TwoAxleDrives are types! It could have been int/string/classname
    // it is exactly the same, we follow the pattern
    //      TYPE VARIABLE_NAME
    //
    // We can also make a parameter OPTIONAL when we provide a DEFAULT value:
    //      TYPE VARIABLE_NAME = DEFAULT_VALUE
    //
    // Having a default value allows us to NOT specify it calling the function, so:
    //      Vehicle::factory(TRAILER) is equivalent to Vehicle::factory(TRAILER, NONE)
    //
    // Notice: when we're inside the class we don't need to use the scope resolution
    // operator to access the enum values. As we don't need to use :: to access static
    // variables or functions. We are within the scope where they are visible/defined
    static Vehicle* factory(TwoAxleVehicles type, TwoAxleDrives drive = NONE) {
        // "new" returns a POINTER, remember! With "new" we reserve memory in the HEAP
        // BUT! REMEMBER! When we use "new" we should always use a "delete" somwehere
        Vehicle* vehicle = new Vehicle();

        vehicle->type = type;
        vehicle->drive = drive;

        return vehicle;
    }
    // ^ if we did not create the object with "new" it would have been destroyed when
    // we got out of the scope. Therefore our only option to have a function return
    // something created inisde of it without getting destroyed is by using "new"

    float getKM() {
        return this->km;
    }

    // We overload the () operator. The structure of the overloading method is as always:
    //      RETURN_TYPE operatorTHE_OPERATOR(/* PARAMETERS */) { /* BODY */ }
    //
    // We just replace THE_OPERATOR with the operator we overload, e.g:
    //      operator+=(/* */)
    //      operator+(/* */)
    //      operator&&(/* */)
    //
    // when we define the overloading method within the body of the class we assume that
    // the first operand of an operation is ALWAYS the instance/object. So:
    //      instance++;             // this = instance          <-- ++ is unary operator
    //      -instance;              // this = instance          <-- - as an unary operator
    //          ^ keep in mind the following example:
    //                                      int a = 1;
    //                                      int b = -a;         <-- -a is calling unary operator -
    //
    //      a - b;                  // this = a                 <-- - as a binary operator
    //          ^ b will always be the only argument of our overloading method, it can be
    //              ANY type. It can be int, float, a class, an enum, a string, etc.
    void operator()(float km) {
        this->km += km;
    }
};

int main() {
    // You notice how we use the scope resolution operator :: ?
    // We would have not been able to access the enum values if they were not in the
    // public scope!
    Vehicle* bike = Vehicle::factory(Vehicle::BIKE);
    Vehicle* bmw = Vehicle::factory(Vehicle::CAR, Vehicle::REAR);

    // original comment: let's drive it
    // explanation: this is a function call, we're using the object as a function.
    // () is an operator we can overload (see void operator()(float km) above)
    //
    // It would have been easier to spot if it was:
    //      Vehicle bmw = Vehicle();
    //      bmw(100.8);
    //
    // but we have a POINTER so we need to dereference it by doing:
    //      (*bmw)
    //
    // and afterwards calling the result of the operation as a function
    (*bmw)(100.8);
    // ^ it would have been the same as writing a method:
    //      void drive(float km) { /* */ }
    //
    // and calling it:
    //      bmw->drive(100.8);

    cout << "BMW, " << bmw->getKM() << "km" << endl; // BMW, 100.8km

    delete bike, bmw;
}