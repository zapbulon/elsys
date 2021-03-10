package com.elsys;

import java.util.Scanner;

public class Trivia {
    public static final short questionsCount = 4;

    private Player[] players;
    private Question[] questions;

    /**
     * Sets the competitors
     *
     * @param players
     * @return self
     */
    public Trivia setPlayers(Player[] players) {
        this.players = players;

        return this;
    }

    /**
     * Sets the questions to ask the players
     *
     * @param questions
     * @return self
     */
    public Trivia setQuestions(Question[] questions) {
        this.questions = questions;

        return this;
    }

    /**
     * Runs the game by asking each question to each player and calculates the points, determining the winner
     */
    void play() {
        Scanner consoleScanner = new Scanner(System.in);
        consoleScanner.useDelimiter("\n");

        System.out.println("Welcome to the most awesome terminal trivia game!");
        System.out.println("Here comes our first question ...\n");

        for (Question question : this.questions) {
            System.out.println(question.getText());

            double[] answers = new double[this.players.length];

            for (int i = 0; i < this.players.length; i++) {
                System.out.printf("What's your answer, %s?\n\t", this.players[i].getName());

                while (!consoleScanner.hasNextDouble()) {
                    consoleScanner.next();
                    System.out.print("Please enter a valid numeric answer:\n\t");
                }

                answers[i] = consoleScanner.nextDouble();
            }

            // There is a bug here - if they are even we're not gonna give points to both of them
            double closestDistance = Integer.MAX_VALUE;
            int bestAnswerIndex = 0;

            for (int i = 0; i < answers.length ; i++) {
                double diff = Math.abs(answers[i] - question.getAnswer());

                if (diff < closestDistance) {
                    closestDistance = Math.abs(answers[i] - question.getAnswer());
                    bestAnswerIndex = i;
                }
            }

            System.out.printf(
                    "\nThe correct answer is %f. The winner of the round is %s\n\n",
                    question.getAnswer(),
                    this.players[bestAnswerIndex].getName()
            );

            if (question.getDifficulty() < 4) {
                this.players[bestAnswerIndex].addPoints(question.getDifficulty());

                System.out.printf("Giving %s %d points\n", this.players[bestAnswerIndex].getName(), question.getDifficulty());
                System.out.printf("They now have %f points. \n", this.players[bestAnswerIndex].getPoints());
            } else {
                // I wrote the whole code in a way that allows more than 2 competitors. So I'm changing
                // the rules so it can work. I'm gonna deduct points from each opponent
                int i = 0;
                for (Player opponent: this.players) {
                    if (opponent != this.players[bestAnswerIndex]) {
                        double diff = Math.abs(answers[i] - question.getAnswer());
                        double deduct = Math.abs(diff - closestDistance);

                        opponent.addPoints(-deduct);

                        System.out.printf(
                                "Deducting %f points from %s's total\n",
                                deduct,
                                opponent.getName()
                        );
                    }

                    i++;
                }
            }
        }

        System.out.println("\nThis was our last question! Now let's calculate the results ...");
        System.out.println("And the results are .... (drum roll) ....");

        for (Player player: this.players) {
            System.out.printf("%s: %f points\n", player.getName(), player.getPoints());
        }
    }
}
