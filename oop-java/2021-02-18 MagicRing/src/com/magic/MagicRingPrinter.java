package com.magic;

import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Objects;

public class MagicRingPrinter {
    // Let's set some defaults
    String color = "silver";
    String outerInscription;
    String innerInscription;

    MagicRing.Size size = MagicRing.Size.S;

    String[] jewels;
    String[] powers;

    public MagicRingPrinter() {
        this.jewels = new String[]{ null, null, null };
        this.powers = new String[]{ null, null, null };
    }

    public MagicRingPrinter setColor(String newValue) {
        this.color = newValue;

        return this;
    }

    public MagicRingPrinter setOuterInscription(String newValue) {
        this.outerInscription = newValue;

        return this;
    }

    public MagicRingPrinter setInnerInscription(String newValue) {
        this.innerInscription = newValue;

        return this;
    }

    public MagicRingPrinter setSize(MagicRing.Size newValue) {
        this.size = newValue;

        return this;
    }

    public MagicRingPrinter addJewel(String newValue) {
        boolean added = this.addToArrayProperty(this.jewels, newValue);

        if (!added) {
            throw new InputMismatchException("No empty slot for a new jewel");
        }

        return this;
    }

    public MagicRingPrinter addPower(String newValue) {
        boolean added = this.addToArrayProperty(this.powers, newValue);

        if (!added) {
            throw new InputMismatchException("No empty slot for a new jewel");
        }

        return this;
    }

    public MagicRing print() {
        // Now, this is a complex constructor and following the Builder pattern
        // we don't need to know about it. More, any changes to the construction
        // process - we don't need to know about it. Whoever develops the package
        // takes care of it all
        return new MagicRing(
                this.color,
                this.outerInscription,
                this.innerInscription,
                this.size,
                // a fancy way to create a new array with all nulls removed
                Arrays.stream(this.jewels).filter(Objects::nonNull).toArray(String[]::new),
                Arrays.stream(this.powers).filter(Objects::nonNull).toArray(String[]::new)
        );
    }

    private boolean addToArrayProperty(String[] array, String newValue) {
        boolean added = false;

        for (int i = 0; i < array.length; i++) {
            if (array[i] == null) {
                array[i] = newValue;

                added = true;
                break;
            }
        }

        return added;
    }



}
