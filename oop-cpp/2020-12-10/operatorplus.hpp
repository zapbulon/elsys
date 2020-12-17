#ifndef OPERATOR_PLUS_HPP
#define OPERATOR_PLUS_HPP

#include <iostream>
#include "operator.hpp"

using namespace std;

class OperatorPlus : public Operator::Binary {

public:
    OperatorPlus() : Operator::Binary("plus", '+') {}

    double calculate(double a, double b) {
        return a + b;
    }
};

#endif