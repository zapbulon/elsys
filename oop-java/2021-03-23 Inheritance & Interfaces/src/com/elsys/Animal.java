package com.elsys;

public abstract class Animal {
    String species;

    Animal(String species) {
        this.species = species;
    }

    public String getSpecies() {
        return this.species;
    }

    // an abstract method makes our class abstract by definition
    public abstract void move(Biome biome);
}
