package com.elsys;

import com.magic.MagicRing;
import com.magic.MagicRingPrinter;

public class Main {

    public static void main(String[] args) {
        MagicRingPrinter printer = new MagicRingPrinter();

        MagicRing ring = printer.setSize(MagicRing.Size.ONE_SIZE_FITS_ALL)
                                .setOuterInscription("One Ring to rule them all, One ring to find them, " +
                                        "One Ring to bring them all, and in the darkness bind them")
                                .addPower("Teleportation")
                                .addPower("Invisibility")
                                .addPower("Sauron can see you")
                                .print();

        ring.describe();

        // Uncomment the line below to see the notice that the constructor
        // "Cannot be accessed from outside package". Our constructor does
        // not have an access modifier so it's only package access (you
        // can't create objects from outside the package). Therefore - our
        // MagicRing objects are immutable!
        // MagicRing ring = new MagicRing(); // nope, cant do it
    }
}
