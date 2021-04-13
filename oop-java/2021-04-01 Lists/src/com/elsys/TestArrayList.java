package com.elsys;

import java.util.*;
import static java.lang.System.out;

public class TestArrayList  {

    public static void test() {
        // this is how we define a ArrayList var
        ArrayList<String> list = new ArrayList<String>();

        // this is how we add values, they don't have to be unique
        list.add("Test 1");
        list.add("Test 2");
        list.add("Test 1");
        list.add("Test 3");

        out.printf("List size is %d\n", list.size());
        out.printf("List 2nd element is %s\n", list.get(1));

        // We can ensure the list capacity upfront
        // list.ensureCapacity(20);
        // out.printf("List 6th element is %s\n", list.get(5));

        // we can use for loop to iterate
        out.println("\nTraverse with for:");
        for (String s: list) {
            out.println(s);
        }

        // this is how we remove the first element with the provided value
        list.remove("Test 1");

        // we can use iterators here too
        Iterator itr = list.iterator();

        out.println("\nTraverse with Iterator");
        while (itr.hasNext()) {
            out.println(itr.next());
        }

        // remove all will remove ... all instances of an element
        list.add("Test 2");
        list.removeAll(Arrays.asList(new String[] { "Test 1", "Test 2" }));

        out.println("\nDump with println");
        out.println(list);

        // two different ways to convert ArrayList to array
        // ArrayList.toArray()
        Object[] objects = list.toArray();

        // T[] ArrayList.toArray(T[])
        out.println("\ntoArray(T[]) with larger array");
        String[] target = new String[2];
        String[] converted = list.toArray(target);

        out.println(target);
        out.println(converted);

        out.println("\ntoArray(T[]) with smaller array");
        String[] target1 = new String[0];
        String[] converted1 = list.toArray(target1);

        out.println(target1);
        out.println(converted1);

        // some additional methods to try
        out.println("\nClear, isEmpty, addAll and contains");

        out.printf("Is empty? - %s\n", list.isEmpty());
        list.clear();
        out.printf("Is empty? - %s\n", list.isEmpty());

        list.addAll(Arrays.asList(new String[] { "A", "B", "C" }));
        out.println(list);

        out.printf("List has `B`: %s\n", list.contains("F"));
        out.printf("List has [`A`, `C`]: %s\n", list.containsAll(new ArrayList<String>(Arrays.asList(new String[] { "A", "F" }))));
    }



    public static void equals() {
        ArrayList<String> list1 = new ArrayList<String>();
        list1.add("C++");
        list1.add("Java");

        ArrayList<String> list2 = new ArrayList<String>();
        list2.add("Java");
        list2.add("C++");

        out.println(list1.equals(list2));

        Collections.swap(list2, 0, 1);
        list1.add("Python");

        out.println(list1.equals(list2));
    }

    public static void sort() {
        ArrayList<String> countries = new ArrayList<String>();
        countries.add("Germany");
        countries.add("Denmark");
        countries.add("Bulgaria");
        countries.add("England");

        out.println(countries);
        Collections.sort(countries);
        out.println(countries);
    }
}