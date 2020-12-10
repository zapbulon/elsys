#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <vector>
#include "operator.hpp"

class Calculator {
    vector<double> operands;
    vector<Operator*> operators;
public:
    Calculator() {}

    double process(double operand);

    double process(char o);

    void registerOperator(Operator& op) {
        operators.push_back(&op);
    }
};

#endif