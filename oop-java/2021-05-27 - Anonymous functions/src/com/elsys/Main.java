package com.elsys;

public class Main {

    public static void main(String[] args) {
        /*
            Here is the full tutorial about functional interfaces & anonymous functions:

            https://docs.oracle.com/javase/tutorial/java/javaOO/lambdaexpressions.html
         */
	    PhoneBook phoneBook = new PhoneBook();

	    phoneBook.addContact("Lubo", "Varbanov");
        phoneBook.addContact("Lubo", "Chorbadjiski");
        phoneBook.addContact("Mario", "Metushev");

        /*
            walkFilter will:
             - first filter the records by calling for each one:
                c -> c.lastName.endsWith("ov")

                it is the equivalent of:

                boolean (Contact c) -> {
                    return c.lastName.endsWith("ov");
                }

             - for those that pass the check above (the anonymous function returns true)
               we call the second
         */
        phoneBook.walkFilter(
            c -> c.lastName.endsWith("ov"),
            c -> c.lastName = c.lastName.replaceAll("ov", "off")
        );

        // System.out.println actually fulfills the Consumer<T> interface - receives and
        // Object and returns void
        phoneBook.walkFilter(
            c -> true,
            System.out::println // equivalent to:
                                // c -> System.out.println(c)
                                //
                                //         ... or ...
                                //
                                // void (Contact c) -> {
                                //     System.out.println(c);
                                // }
        );
    }
}
