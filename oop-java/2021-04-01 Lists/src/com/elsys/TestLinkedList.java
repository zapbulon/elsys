package com.elsys;

import java.util.Iterator;
import java.util.LinkedList;

public class TestLinkedList {
    public static void test() {
        LinkedList<String> list = new LinkedList<String>();

        list.add("Test 1");
        list.add("Test 2");
        list.add("Test 1");

        // Traversing with for
        for (String s: list) {
            System.out.println(s);
        }

        // Traversing with Iterator
        Iterator itr = list.iterator();

        while (itr.hasNext()) {
            System.out.println(itr.next());
        }
    }
}
