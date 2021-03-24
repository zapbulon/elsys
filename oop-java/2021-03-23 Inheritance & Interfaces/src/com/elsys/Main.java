package com.elsys;

public class Main {

    public static void main(String[] args) {
        // Let's init a list of `Thing`s (they all implement the Thing interface)
        Human baby = new Human(2, "John");
        Human dad = new Human(32, "George");
        Table table = new Table();
        Football football = new Football();

        // Remember, each class we extend and each interface we implement
        // adds another TYPE to the list of types our objects are gonna
        // have. We can pass our objects to any method requiring any of the
        // types showcased below.
        System.out.printf("Baby is Human?: %s\n", baby instanceof Human);
        System.out.printf("Baby is Mammal?: %s\n", baby instanceof Mammal);
        System.out.printf("Baby is Animal?: %s\n", baby instanceof Animal);
        System.out.printf("Baby is Thing: %s\n", baby instanceof Thing);
        System.out.printf("Baby is Object: %s\n", baby instanceof Object);

        // Both of these lines do exactly the same
        System.out.println(baby);
        System.out.println(baby.toString());

        // Anything that implements the Thing interface can be passed to the
        // `whatIs` method
        baby.whatIs(dad);
        baby.whatIs(football);
        baby.whatIs(table);
    }
}
