package com.elsys;

import java.util.HashSet;
import java.util.Set;

public class Main {

    public static void main(String[] args) {
        SetOperations.show();

        Person a = new Person("123A", "John Atanasoff");
        Citizen kane = new Citizen("123A", "Kane", "Sofia");

        Set<Person> set = new HashSet<Person>();
        set.add(a);
        set.add(kane);

        System.out.println(set);

    }
}
