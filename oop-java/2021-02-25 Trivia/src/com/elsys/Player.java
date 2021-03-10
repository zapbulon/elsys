package com.elsys;

class Player {
    private String name;
    private short age;

    private double points;

    Player(String name, short age) {
        this.name = name;
        this.age = age;
        this.points = 0;
    }

    public String getName() {
        return this.name;
    }

    public double getPoints() {
        return this.points;
    }

    Player addPoints(double points) {
        this.points += points;

        return this;
    }
}
