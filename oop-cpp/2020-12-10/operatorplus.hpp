#ifndef OPERATOR_PLUS_HPP
#define OPERATOR_PLUS_HPP

#include <iostream>
#include "operator.hpp"

using namespace std;

class OperatorPlus : public Operator {

public:
    OperatorPlus() : Operator("plus", '+') {}

    double process(double a, double b) {
        return a + b;
    }
};

#endif