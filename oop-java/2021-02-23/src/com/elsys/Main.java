package com.elsys;

import java.io.FileInputStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // let's init a Scanner and read stuff from the console
        Scanner consoleScanner = new Scanner(System.in);

        // :)))
        while (true) {
            System.out.println("You are in an infinite loop. What's the meaning of life?");

            if (consoleScanner.hasNextInt()) {
                if (consoleScanner.nextInt() == 42) {
                    System.out.println("Correct. Move on, peasant.\n\n");
                    break;
                } else {
                    System.out.println("You're getting closer ...");
                }
            } else {
                consoleScanner.next();
                System.out.println("Nope, try again ...");
            }
        }

        // we close the scanner
        consoleScanner.close();

        // this is how we can check what the CWD is ....
        System.out.println(System.getProperty("user.dir"));

        try {
            // ... so our relative path works later
            Scanner scanner = new Scanner(new FileInputStream("test.csv"));

            // while there is still stuff to read in the file
            while (scanner.hasNextLine()) {
                // read the content of the next line
                String line = scanner.nextLine();

                // create a new scanner, scan the content of the line (string)
                Scanner stringScanner = new Scanner(line);

                // tokenize (split) the line using the following delimiter:
                //      \s*,\s*
                //
                // It is a regex, here is what the parts of the content mean:
                // - In regular expressions, the asterisk is a metacharacter
                //   for zero or more instances of the preceding character
                // - The \s metacharacter is used to find a whitespace character.
                stringScanner.useDelimiter("\\s*,\\s*");

                // now that we've tokenized the string we can safely read
                String fName = stringScanner.next();
                String lName = stringScanner.next();
                int skill = stringScanner.nextInt();

                // using printf, pretty cool, missed it
                System.out.printf("Name: %s %s, skill %d\n", fName, lName, skill);
            }

            // don't forget to close the scanner!!!
            scanner.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println(e.getMessage());
        }
    }
}
