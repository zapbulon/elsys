#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream log;
    log.open("log.txt", ios::trunc);
    log << "This is SAPRTAAAA!" << endl;
    log.close();
    
    ifstream in;
    string content;
    in.open("log.txt");
    in >> content;

    cout << "File opened? " << boolalpha << !in.fail() << endl;

    // No it's not, this is just the first word
    cout << "The file content is: " << endl << content << endl;
    cout << "Reached the end of the file? " << boolalpha << in.eof() << endl;
    
    getline(in, content);
    cout << "The file content is: " << endl << content << endl;
    cout << "Reached the end of the file? " << in.eof() << endl;

    getline(in, content);
    cout << "Reached the end of the file? " << in.eof() << endl;

    in.close();

    in.open("random.txt");
    cout << "File opened? " << boolalpha << !in.fail() << endl;
    
    return 0;
}


