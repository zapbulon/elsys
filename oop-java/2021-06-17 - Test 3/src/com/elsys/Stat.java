package com.elsys;

import java.util.InputMismatchException;

public class Stat<T extends Comparable> {
    String name;
    T max;

    class Value {
        T current;
        T potential;

        Value(T current, T potential) {
            if (current.compareTo(max) > 0 || potential.compareTo(max) > 0) {
                throw new InputMismatchException("The max value for " + name + " is " + max);
            }

            this.current = current;
            this.potential = potential;
        }

        String getStatName() {
            return name;
        }
    }

    Stat(String name, T max) {
        this.name = name;
        this.max = max;
    }
}
