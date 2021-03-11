package com.elsys;

public class Calculator {
    public int addPositive(int a, int b) {
        if (a < 0 || b < 0) {
            throw new IllegalArgumentException("Arguments must be positive");
        }

        return a + b;
    }

    public double add(int a, double b) {
        return (double ) a + b;
    }
}
