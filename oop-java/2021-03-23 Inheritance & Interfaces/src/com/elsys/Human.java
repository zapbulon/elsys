package com.elsys;

// By using "extends" we inherit the class Mammal
public class Human extends Mammal {
    int age;
    String name;

    Human(int age, String name) {
        // By using `super` we can call a specific parent constructor -
        // in this case one that accepts a single String
        super("home sapiens");

        this.age = age;
        this.name = name;
    }

    // Anything that implements the Thing method will have the getLabel
    // method so we can do our work and state what it is
    void whatIs(Thing thing) {
        System.out.printf("This is a(n) %s\n", thing.getLabel());
    }

    // By default all classes in Java extend the Object class and it provides
    // a method used by System.out.print to print information for any object
    // provided. So we can override this method and change the behaviour
    public String toString() {
        return String.format("A human, called %s", this.name);
    }

    public void move(Biome biome) {
        System.out.printf("the human moves in %s\n", biome.toString());
    }
}
