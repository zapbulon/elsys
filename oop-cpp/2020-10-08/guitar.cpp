#include <iostream>

using namespace std;

class BadGuitarStringPosition {};

// Let's use a class with customized message to throw 
class BadStringThickness {
    float thickness;
    string instrument;
public:
    BadStringThickness(string instrument, float thickness) {
        this->thickness = thickness;
        this->instrument = instrument;
    }

    string getMessage() {
        return string("Invalid ") + this->instrument + string(" string thickness ") + to_string(this->thickness);
    }
};

class ElectricGuitarString {
    float thickness; // in cm
    
public:
    static const char* instrument;

    ElectricGuitarString() {
        this->thickness = 0;
    }

    ElectricGuitarString(float thickness) {
        this->thickness = thickness;

        if (thickness < 0.2 || thickness > 1.5) {
            throw BadStringThickness(this->instrument, thickness);
        }
    }
    
    float getThickness() {
        return this->thickness;
    }    
};

const char* ElectricGuitarString::instrument = "electric guitar";

class ElectricGuitar {
    ElectricGuitarString strings[6];
    
public:
    ElectricGuitar() {}
    
    void replaceString(ElectricGuitarString string, short position) {
        if (position < 1 || position > 6) {
            throw BadGuitarStringPosition();
        }

        if (position > 1 && this->strings[position-2].getThickness() != 0 
            && this->strings[position-2].getThickness() > string.getThickness()) {
            throw position;
        }

        if (position < 6 && this->strings[position].getThickness() != 0 
            && this->strings[position].getThickness() < string.getThickness()) {
            throw position;
        }

        this->strings[position-1] = string;
    }
};

int main() {
    try {
        ElectricGuitar guitar = ElectricGuitar();
        ElectricGuitarString strings[6] {
            ElectricGuitarString(0.2),
            ElectricGuitarString(0.4),
            ElectricGuitarString(0.8),
            ElectricGuitarString(1),
            ElectricGuitarString(1.2),
            ElectricGuitarString(1.4),
        };

        for (short i = 0; i < 6; i++) {
            cout << "We have an " << strings[i].instrument << " string: " << strings[i].getThickness() << endl;
            cout << "Trying to set it at position: " << i+1 << endl;

            guitar.replaceString(strings[i], i+1);
        }
    } catch (short position) {
        cout << "Tried setting a string with wrong thickness at position " << position << ". Please rearrange" << endl;
    } catch (BadGuitarStringPosition e) {
        cout << "Tried setting a string at a non-existing position. Use [1:6]" << endl;
    } catch (BadStringThickness e) {
        cout << "An error occured: " << e.getMessage() << endl;
    }
    
    return 0;
}