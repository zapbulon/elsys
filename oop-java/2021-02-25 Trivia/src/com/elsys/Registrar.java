package com.elsys;

import java.util.Scanner;

public class Registrar {
    public static final short minAge = 14;

    /**
     * Reads player details from console
     *
     * @param numberOfPlayers
     * @return Player[]
     */
    public static Player[] registerPlayers(short numberOfPlayers) {
        Scanner consoleScanner = new Scanner(System.in);
        consoleScanner.useDelimiter("\n");

        Player[] players = new Player[numberOfPlayers];

        short currentPlayer = 0;
        while (true) {
            System.out.printf("Please enter player %d's name:\n\t", currentPlayer+1);
            String name = consoleScanner.next();

            System.out.printf("What's %s's age:\n\t", name);
            while (!consoleScanner.hasNextShort()) {
                consoleScanner.next();
                System.out.print("Please enter valid age:\n\t");
            }

            short age = consoleScanner.nextShort();
            if (age < Registrar.minAge) {
                System.out.println("Sorry, this competitor is underage.");
                continue;
            }

            players[currentPlayer++] = new Player(name, age);

            if (currentPlayer == numberOfPlayers) {
                break;
            }
        }

        return players;
    }
}
