#include <iostream>
#include <sstream>

using namespace std;

int main() {

    cout << "Base:" << endl;
    cout << dec << 20 << endl
         << hex << 20 << endl
         << oct << 20 << endl
         << showbase << 10 << endl
         << dec << noshowbase << endl << endl;

    cout << "Boolalpha:" << endl;
    cout << true << " " << boolalpha << true << endl << endl;
    
    cout << "Showpos:" << endl;
    cout << showpos << 3.14 << noshowpos << endl << endl;
    
    cout << "Uppercase:" << endl;
    cout << hex << "abc " << 214 << " " << uppercase << " abc " << 214 << nouppercase << dec << endl << endl;
    
    cout << "Width & fill: " << endl;
    cout.width(4);
    cout.fill('#');
    cout << -12 << endl;
    cout.width(4);
    cout << left << -12 << endl;
    cout.width(4);
    cout << internal << -12 << endl << endl;

    cout << "Alternative writing: " << endl;
    cout.write("hello", 3) << endl;
    cout.put('a') << endl;

    return 0;
}