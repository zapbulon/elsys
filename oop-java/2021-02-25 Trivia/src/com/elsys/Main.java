package com.elsys;

public class Main {

    public static void main(String[] args) {
        Trivia trivia = new Trivia();

        trivia.setQuestions(Question.loadFromFile("questions.dsv", Trivia.questionsCount))
                .setPlayers(Registrar.registerPlayers((short) 2))
                .play();
    }
}
