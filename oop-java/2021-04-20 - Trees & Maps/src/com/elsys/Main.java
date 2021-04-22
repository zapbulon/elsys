package com.elsys;

import java.util.Map;
import java.util.HashMap;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {
        // This is how we create a HashMap
        HashMap<String, Integer> capitals = new HashMap<>();

        // Easy to put in pairs
        capitals.put("Bulgaria", 100);
        capitals.put("England", 200);

        System.out.println(capitals);

        // Try all these methods
        // .clear
        // .size
        // .get
        // .getOrDefault
        // .isEmpty
        // .replace
        // .containsKey
        // .containsValue
        // .keySet
        // .values

        // iterate using Map.Entry<K, V>
        for (Map.Entry<String, Integer> entry : capitals.entrySet()) {
            System.out.println(entry.getKey() + ' ' + entry.getValue());
        }

        // compute uses a clojure to compute a new value for the key
        capitals.compute("Bulgaria", (k, v) -> v * 3);

        // iterate using forEach
        capitals.forEach((k, v) -> System.out.println(k + ' ' + v));

        System.out.println("------------------------------");

        // These are the 4 containers we learn. The ones on the left use the ones
        // on the right internally:
        //
        // HashSet -> HashMap
        // TreeSet -> TreeMap

        // A tree of Strings
        TreeSet<String> tree = new TreeSet<>();

        // Simply add them
        tree.add("Sofia");
        tree.add("Varna");
        tree.add("Ahtopol");
        tree.add("Plovdiv");
        tree.add("Pleven");

        System.out.println(tree);

        System.out.println("------------------------------");

        // Check all the fun methods we have:
        // https://www.javatpoint.com/java-treeset
        System.out.println(tree.ceiling("Plovdia"));

        System.out.println(tree.tailSet("Plovdiz"));
        System.out.println(tree.subSet("Plovdiv", "Varna"));
        System.out.println(tree.subSet("Plovdiv", false, "Varna", true));

        // An easy way to traverse through the TreeSet
        for (String element: tree) {
            System.out.println(element);
        }
    }
}
