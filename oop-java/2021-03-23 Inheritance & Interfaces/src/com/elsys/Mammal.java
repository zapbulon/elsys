package com.elsys;

// We are not implementing the Animal.move method so we have to declare
// our class abstract
public abstract class Mammal extends Animal implements Thing {
    Mammal(String species) {
        super(species);
    }

    public String getLabel() {
        return "a human";
    }
}
