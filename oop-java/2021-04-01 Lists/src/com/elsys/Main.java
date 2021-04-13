package com.elsys;

import java.util.ArrayList;
import java.util.Collections;

public class Main {

    public static void main(String[] args) {
        // TestArrayList.test();
        // TestLinkedList.test();

        // TestArrayList.equals();
        // TestArrayList.sort();

        ArrayList<Car> cars = new ArrayList<Car>();
        cars.add(new Car("Mercedes-Benz", 120000, 255));
        cars.add(new Car("Toyata", 55000, 115));
        cars.add(new Car("BMW", 95000, 230));

        System.out.println(cars);

        Collections.sort(cars, new Car.PriceComparator());

        System.out.println(cars);
    }
}
