#include "calculator.hpp"

double Calculator::process(double operand) {
    operands.push_back(operand);

    return operands.back();
}

double Calculator::process(char o) {
    for (auto op : operators) {
        if (op->get() == o) {
            op->process(this->operands);
            return operands.back();
        }
    }

    throw "Calculator: operator `" + string(1, o) + "` unknown";
}