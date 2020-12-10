#include <iostream>
#include "calculator.hpp"
#include "operatorplus.hpp"
#include "operatorminus.hpp"

using namespace std;

int main() {
    Calculator calculator;

    OperatorPlus plus;
    OperatorMinus minus;

    calculator.registerOperator(plus);
    calculator.registerOperator(minus);

    try {
        cout << calculator.process(2.0) << endl;
        cout << calculator.process(4.8) << endl;
        cout << calculator.process('+') << endl;
        cout << calculator.process(2.8) << endl;
        cout << calculator.process('-') << endl;
    } catch (string ex) {
        cout << ex << endl;
    }

    return 0;
}