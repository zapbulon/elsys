package com.elsys;

public class Citizen extends Person {
    String city;

    public Citizen(String id, String name, String city) {
        super(id, name);
        this.city = city;
    }
}
