#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

int main() {
    int i;

    cin.exceptions(ios_base::failbit);

    try {
        cout << "We expect an int:" << endl;
        cin >> i;

        cout << "Value is: " << i << endl;
        cout << "Value is good? " << boolalpha << cin.good() << endl;
    } catch (...) {
        cout << "Meh, failed. What did I tell you? A NUMBER!" << endl;

        // clear the error flags, otherwise cin is unusable afterwards
        cin.clear();
    }

    string name;
    cout << endl << "We're gonna read a whole line. Give us your full name:" << endl;

    // there is an \n left in the stream (we left it there when we did input the number ... if we pressed enter) 
    // which will make our life miserable - so with .ignore() we remove it. 
    //  
    // First argument: how many chars to ignore
    // Second argument: stop ignoring when you reach it (a newline)
    // 
    // std::numeric_limits<std::streamsize>::max() gives us the maximum amount of chars 
    // the buffer may have. We can also use some random big number.
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    getline(cin, name);
    cout << "Cool name, " << name << '!' << endl;

    return 0;
}