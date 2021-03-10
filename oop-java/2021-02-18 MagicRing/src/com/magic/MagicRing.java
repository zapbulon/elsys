package com.magic;

import java.util.Arrays;

public class MagicRing {
    // see, an enum
    public enum Size { S, M, L, ONE_SIZE_FITS_ALL }

    String color;
    String outerInscription;
    String innerInscription;

    MagicRing.Size size;

    String[] jewels;
    String[] powers;

    MagicRing(
            String color,
            String outerInscription,
            String innerInscription,
            MagicRing.Size size,
            String[] jewels,
            String[] powers
    ) {
        this.color = color;
        this.outerInscription = outerInscription;
        this.innerInscription = innerInscription;
        this.size = size;
        this.jewels = jewels;
        this.powers = powers;
    }

    public void describe() {
        System.out.printf("This is %s ring, size %s. ", this.color, this.size.toString());

        if (this.outerInscription != null) {
            System.out.printf("On the outside it says \"%s\". ", this.outerInscription);
        }

        if (this.innerInscription != null) {
            System.out.printf("On the inside it says \"%s\". ", this.innerInscription);
        }

        if (this.jewels != null && this.jewels.length > 0) {
            System.out.printf("It has the following jewels %s. ", Arrays.toString(this.jewels));
        }

        if (this.powers != null && this.powers.length > 0) {
            System.out.printf("It has the following powers %s. ", Arrays.toString(this.powers));
        }
    }
}
