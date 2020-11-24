#include <iostream>
#include <map>

using namespace std;

class Vehicle {
public:
    enum Drive { FRONT, REAR, ALL, NONE };
    enum Type { BIKE, CAR, TRAILER, TRUCK }; // let's add a TRUCK
private:
    // as we can have an enum type defined within the class and accessed with the
    // scope resolution
    class Tire {
    public:
        float wear;   // we're gonna measure the Tire wear in KM
        Tire() : wear(0) {}
    };

    Type type;
    Drive drive;

    float km;

    // we're gonna use "new" to allocate an array of Tire objects. Without "new"
    // we won't be able to dynamically specify the array size. REMEMBER, "new"
    // returns a POINTER to the beginning of the allocated memory block in the HEAP
    //
    // Tires are getting worn based on the axle they are mounted to and it doesn't
    // matter if they are left/right. So we're gonna keep the state of ALL tires on
    // an axle with a single Tire object. Therefore:
    //      Tire[2] will mean we have two axles. Let's count them front-to-back -
    //              index 0 will be front, index 1 will be back
    //      Tire[3] will mean we have 3 axles. Index 0 - front, 1 - middle, 2 - back
    Tire* axles;

    // let's use a map from STL, we're gonna have a static var telling us how many axles
    // the vehicle type has
    static map<Type, int> axlesCount;
public:
    Vehicle() : km(0) {}

    ~Vehicle() {
        delete[] this->axles;
    }

    static Vehicle* factory(Type type, Drive drive = NONE) {
        // "new" returns a POINTER, remember! With "new" we reserve memory in the HEAP
        // BUT! REMEMBER! When we use "new" we should always use a "delete" somwehere
        Vehicle* vehicle = new Vehicle();

        vehicle->type = type;
        vehicle->drive = drive;

        vehicle->axles = new Tire[vehicle->getAxlesCount()];

        return vehicle;
    }

    // just a lazy demonstration how to use a range for on a map:
    //      .first      // the key in the map pair
    //      .second     // the value in the map pair
    static void printAxlesCount() {
        // ENUMS actually get assgined int values. So for axle.first we're gonna get
        // auto incremented int values - 0, 1, 2 & 3

        for (auto axle : Vehicle::axlesCount) {
            cout << axle.first << ": " << axle.second << endl;
        }
    }

    // how many axles does the current vehicle has?
    int getAxlesCount() const {
        return this->axlesCount[this->type];
    }

    float getKM() {
        return this->km;
    }

    void operator()(float km) {
        this->km += km;

        int axlesCount = this->getAxlesCount();
        for (int i = 0; i < axlesCount; i++) {
            float coeff = (this->drive == FRONT && i == 0)              // front wheel drive and it is front axle
                            ||                                          // or ....
                          (this->drive == REAR && i == axlesCount - 1)  // rear wheel drive and it's the rear axle
                            ? 1.2
                            : 1;

            this->axles[i].wear += km * coeff;
        }
    }

    // check the operator explanation from the previous file. Nothing too funky,
    // we're just exposing the tires condition if you access them using [] on
    // the vehicle iteself, so after:
    //          Vehicle* truck = Vehicle::factory(Vehicle::TRUCK);
    //          (*truck)[1] will give us access to the axle (Tire) with index 1 (middle axle)
    //
    // Notice: we return a reference to the internal array element so we don't copy it
    const Tire& operator[](int index) const {
        return this->axles[index];
    }
};

// we can't give a static variable value within the class definition, so we do it outside
map<Vehicle::Type, int> Vehicle::axlesCount = {
    { BIKE, 2},
    { CAR, 2 },
    { TRAILER, 2},
    { TRUCK, 3 }
};

// We can't overload the << operator as a class member function, it always has to be done
// outside of the class body. It may be a friend function.
ostream& operator<<(ostream& out, const Vehicle& vehicle) {
    int axlesCount = vehicle.getAxlesCount();

    for (int i = 0; i < axlesCount; i++) {
        string name = i == 0                    // is it front axle?
                        ? "front"               // - name it "front"
                        : (i == axlesCount - 1  // else - is it last axle?
                            ? "rear"            // - name it "rear"
                            : "middle");        // else (any other case) - name it "middle"

        cout << name << ": " << vehicle[i].wear << "; ";
    }

    return out;
}

int main() {
    Vehicle::printAxlesCount();

    Vehicle* bmw = Vehicle::factory(Vehicle::CAR, Vehicle::REAR);
    Vehicle* vw = Vehicle::factory(Vehicle::CAR, Vehicle::FRONT);
    Vehicle* truck = Vehicle::factory(Vehicle::TRUCK);

    // let's drive them
    (*bmw)(120);
    (*vw)(120);
    (*truck)(120);

    cout << *bmw << endl; // front: 120; rear: 144;
    cout << *vw << endl; // front: 144; rear: 120;
    cout << *truck << endl; // front: 120; middle: 120; rear: 120;

    cout << "Truck middle axle tires wear: " << (*truck)[1].wear << "km" << endl; // Truck middle axle tires wear: 120km

    delete bmw, vw, truck;
}