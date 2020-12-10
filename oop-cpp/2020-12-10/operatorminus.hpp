#ifndef OPERATOR_MINUS_HPP
#define OPERATOR_MINUS_HPP

#include <iostream>
#include "operator.hpp"

using namespace std;

class OperatorMinus : public Operator {

public:
    OperatorMinus() : Operator("minus", '-') {}

    double process(double a, double b) {
        return b - a;
    }
};

#endif