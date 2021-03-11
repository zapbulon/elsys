package com.elsys;

import org.junit.jupiter.api.*;

import static org.junit.jupiter.api.Assertions.*;

class CalculatorTest {
    Calculator calc;

    @BeforeEach
    void setUp() {
        this.calc = new Calculator();
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    @DisplayName("Adding positive integers")
    void addPositiveInt() {
        assertAll(
                () -> assertEquals(3, calc.addPositive(1, 2)),
                () -> assertEquals(7, calc.addPositive(5, 2))
        );
    }

    @Test
    @DisplayName("Adding positive integers does not accept negative numbers")
    void addPositiveIntException() {
        assertThrows(
                IllegalArgumentException.class,
                () -> calc.addPositive(-1, 2)
        );
    }

    @Test
    @DisplayName("Adding int and double")
    void addIntAndDouble() {
        assertEquals((double) 3.1, calc.add(1, 2.1));
    }
}