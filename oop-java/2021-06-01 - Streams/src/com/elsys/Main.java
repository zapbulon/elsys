package com.elsys;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) {
	    /*
	        Terminal operations list:
            https://www.codejava.net/java-core/collections/java-8-stream-terminal-operations-examples

                1. allMatch()
                2. anyMatch()
                3. noneMatch()
                4. collect()
                5. count()
                6. forEach()
                7. min()
                8. max()
                9. reduce()


            Intermediate (non-terminal) operations list:
            https://www.javacodegeeks.com/2020/04/java-8-stream-intermediate-operations-methods-examples.html

                1. filter()
                2. map()
                3. flatMap()
                4. distinct()
                5. sorted()
                6. peek()
                7. limit()
                8. skip()
	     */

        int[] numbers = {123, 456, 789, 246, 135, 802, 791};

        int sum = Arrays.stream(numbers).reduce(0, (x, y) -> (x + y));

        System.out.println("sum = " + sum);


        List<String> result = Stream.of("a", "b", "c")
                                    .map(val -> val.concat("x"))
                                    .collect(Collectors.toList());

        System.out.println(result);

        /*
            class Optional<T>
            https://docs.oracle.com/javase/8/docs/api/java/util/Optional.html
            https://www.baeldung.com/java-optional
         */
    }
}
