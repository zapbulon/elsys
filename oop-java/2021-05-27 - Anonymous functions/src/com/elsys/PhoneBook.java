package com.elsys;

import java.util.ArrayList;
import java.util.function.Consumer;
import java.util.function.Predicate;

public class PhoneBook {
    ArrayList<Contact> contacts;

    PhoneBook() {
        this.contacts = new ArrayList<Contact>();
    }

    void addContact(String firstName, String lastName) {
        this.contacts.add(new Contact(firstName, lastName));
    }

    /*
        We use the following functional template interfaces from java.util.function:

        interface java.util.function.Predicate<T> {
            boolean test(T t);
        }

        interface java.util.function.Consumer<T> {
            void accept(T t);
        }

        here you can find full list of functional interfaces in java.util.function:
            https://docs.oracle.com/javase/8/docs/api/java/util/function/package-summary.html
     */
    void walkFilter(Predicate<Contact> filter, Consumer<Contact> consumer) {
        for (Contact contact : this.contacts) {
            if (filter.test(contact)) {
                consumer.accept(contact);
            }
        }
    }
}
