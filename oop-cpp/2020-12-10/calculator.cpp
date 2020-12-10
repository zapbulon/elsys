#include "calculator.hpp"

double Calculator::process(double operand) {
    operands.push_back(operand);

    return operands.back();
}

double Calculator::process(char o) {
    for (auto op : operators) {
        if (op->get() == o) {
            double a = operands.back();
            operands.pop_back();

            double b = operands.back();
            operands.pop_back();

            operands.push_back(op->process(a, b));
            return operands.back();
        }
    }

    throw "Calculator: operator `" + string(1, o) + "` unknown";
}