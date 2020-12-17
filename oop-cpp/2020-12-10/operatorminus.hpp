#ifndef OPERATOR_MINUS_HPP
#define OPERATOR_MINUS_HPP

#include <iostream>
#include "operator.hpp"

using namespace std;

class OperatorMinus : public Operator::Binary {

public:
    OperatorMinus() : Operator::Binary("minus", '-') {}

    double calculate(double a, double b) {
        return a - b;
    }
};

#endif