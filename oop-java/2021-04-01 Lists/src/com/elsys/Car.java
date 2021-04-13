package com.elsys;

import java.util.Comparator;

public class Car implements Comparable {

    public static class PriceComparator implements Comparator<Car> {
        @Override
        public int compare(Car car1, Car car2) {
            return car2.price - car1.price;
        }
    }

    int hp;
    String brand;
    int price;

    public Car(String brand, int price, int hp) {
        this.hp = hp;
        this.brand = brand;
        this.price = price;
    }

    @Override
    public int compareTo(Object other) {
        return this.brand.compareTo(((Car) other).brand);
    }

    @Override
    public String toString() {
        return String.format("%s, price: %d, HP: %d", this.brand, this.price, this.hp);
    }
}
