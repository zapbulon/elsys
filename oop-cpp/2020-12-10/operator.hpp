#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <iostream>

using namespace std;

class Operator {
    string name;
    char character; // + - * / ^ ! ~
public:
    Operator(string name, char character)
        : name(name), character(character) {}

    char get() {
        return character;
    }

    string getName() {
        return name;
    }

    virtual double process(double a, double b) = 0;
};

#endif