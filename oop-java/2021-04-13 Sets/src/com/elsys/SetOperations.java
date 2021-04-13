package com.elsys;

import java.util.*;

public class SetOperations
{
    public static void show()
    {
        Integer[] A = {77, 45, 33, 66, 55, 34, 22};
        Integer[] B = {33, 2, 83, 45, 3, 12, 55};

        Set<Integer> set1 = new HashSet<Integer>();
        set1.addAll(Arrays.asList(A));
        Set<Integer> set2 = new HashSet<Integer>();
        set2.addAll(Arrays.asList(B));

        // Finding Union of set1 and set2
        Set<Integer> union = new HashSet<Integer>(set1);
        union.addAll(set2);
        // System.out.print("Union of set1 and set2 is:");
        // System.out.println(union);

        // Finding Intersection of set1 and set2
        Set<Integer> intersection = new HashSet<Integer>(set1);
        intersection.retainAll(set2);
        // System.out.print("Intersection of set1 and set2 is:");
        // System.out.println(intersection);

        // Finding Difference of set1 and set2
        Set<Integer> diff = new HashSet<Integer>(set1);
        diff.removeAll(set2);
        // System.out.print("Difference of set1 and set2 is:");
        // System.out.println(diff);

        // iterator
        Iterator newData = set1.iterator();
        while (newData.hasNext()) {
            System.out.println(newData.next());
        }

        System.out.printf("\n\n");
        for (int value: set2) {
            System.out.println(value);
        }

        // size
        // clear
        // isEmpty
        // remove / removeAll
        // contains / containsAll
    }
}