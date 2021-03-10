package com.elsys;

import java.io.FileInputStream;
import java.util.InputMismatchException;
import java.util.Locale;
import java.util.Scanner;

class Question {
    private String text;
    private double answer;
    private short difficulty;

    Question(String text, double answer, short difficulty) {
        this.text = text;
        this.answer = answer;
        this.difficulty = difficulty;
    }

    /**
     * {@return The text of the question}
     */
    public String getText() {
        return text;
    }

    /**
     * {@return The correct answer}
     */
    public double getAnswer() {
        return answer;
    }

    /**
     * {@return The difficulty level}
     */
    public short getDifficulty() {
        return difficulty;
    }

    /**
     * Reads a set of questions from a DSV file
     *
     * @param filename
     * @return Array of questions read from a file
     */
    public static Question[] loadFromFile(String filename, int questionsCount) {
        // reset the questions
        Question[] questions = new Question[questionsCount];

        try {
            Scanner scanner = new Scanner(new FileInputStream(filename));

            // skip the title row
            if (scanner.hasNextLine()) {
                scanner.nextLine();
            } else {
                throw new InputMismatchException("Input file is empty");
            }

            // while there is still stuff to read in the file
            short lineIndex = 0;
            while (scanner.hasNextLine()) {
                // read the content of the next line
                String line = scanner.nextLine();

                // create a new scanner, scan the content of the line (string), remove leading & trailing quotes
                Scanner stringScanner = new Scanner(line.substring(1, line.length()-1));

                // split the line everywhere you find the following strings:
                //      ";"     |   "; "    |   " ;"    |   " ; "
                // ... where a single space may exist multiple times or not at all
                stringScanner.useDelimiter("\"\\s*;\\s*\"");

                // The `,` we use as a decimal separator in the file is actually standard in Europe.
                // Modern languages are aware of locale differences - e.g. a date in the US is
                // written in the format MM/DD/YYYY ... which is retarded, day is after the month.
                // so ... as I said - modern languages take into account locale differences and
                // provide mechanisms to deal with them. Once we tell the scanner we're using
                // French formatting - reading a float it will look for `,` instead of `.` as a
                // decimal separator. Otherwise it will fail miserably and throw an Exception
                // that `110993,6` is not a double
                stringScanner.useLocale(Locale.FRANCE);

                String text = stringScanner.next();
                double answer = stringScanner.nextDouble();
                short difficulty = stringScanner.nextShort();

                questions[lineIndex++] = new Question(text, answer, difficulty);

                stringScanner.close();
            }

            if (lineIndex < questionsCount) {
                throw new InputMismatchException(
                        String.format("Expected exactly %d questions in file", questionsCount)
                );
            }

            scanner.close();
        } catch (Exception e) {
            System.out.printf("There was an exception reading the trivia file. Error message: [%s]\n", e.getMessage());

            e.printStackTrace();
        }

        return questions;
    }
}
