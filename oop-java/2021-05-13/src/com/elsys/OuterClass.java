package com.elsys;

public class OuterClass {
    static int staticVar = 12;

    static class StaticNestedClass {
        StaticNestedClass() {
            System.out.println("Static nested constructor: " + OuterClass.staticVar);
        }
    }

    class InnerClass {
        InnerClass() {
            System.out.println("Inner nested constructor: " + OuterClass.staticVar);
        }
    }

    void testMethod() {
        final int localVar = 42;

        class LocalClass {
            LocalClass() {
                System.out.println("Local class constructed: " + localVar);
            }
        }

        LocalClass localInstance = new LocalClass();

        CustomInterface instance = new CustomInterface() {
            public void test() {
                System.out.println("Test of anonymous class called");
            }
        };

        instance.test();
    }
}
