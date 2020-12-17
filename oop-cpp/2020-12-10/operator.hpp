#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <iostream>
#include <vector>

using namespace std;

class Operator {
    string name;
    char character; // + - * / ^ ! ~
public:
    class Binary;
    class Unary;

    Operator(string name, char character)
        : name(name), character(character) {}

    char get() {
        return character;
    }

    string getName() {
        return name;
    }

    virtual void process(vector<double>& operands) = 0;
};

class Operator::Binary : public Operator {
public:
    Binary(string name, char character) : Operator(name, character) {}

    virtual double calculate(double a, double b) = 0;

    void process(vector<double>& operands) {
        double a = operands.back();
        operands.pop_back();

        double b = operands.back();
        operands.pop_back();

        operands.push_back(this->calculate(b, a));
    }
};

#endif