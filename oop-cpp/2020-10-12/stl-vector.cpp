#include <iostream>
#include <vector>

using namespace std;

int main () {
    vector<int> array;

    cout << "Initial size is " << array.size() << endl 
         << "Initial capacity is " << array.capacity() << endl
         << "Is it empty? " << array.empty() << endl << endl; 

    array.push_back(2);
    array.push_back(3);
    array.push_back(4);

    array.at(2) = 5;

    cout << "Current size is " << array.size() << endl 
         << "Current capacity is " << array.capacity() << endl
         << "Is it empty? " << array.empty() << endl << endl; 

    int sum = 0;
    for (int i=0; i < array.size(); i++) {
        cout << "Element " << i << " is " << array[i] << endl;

        sum += array.at(i);
    }

    cout << "The sum is: " << sum << endl;

    try {
        array.at(3) = 5;
    } catch (std::out_of_range e) {
        cout << "Oops, tried to access out of range element" << endl;
    }
}