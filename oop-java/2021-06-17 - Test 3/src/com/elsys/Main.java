package com.elsys;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;

public class Main {

    // Creates a valid FootballPlayer
    private static FootballPlayer createPlayer(
        String name,
        Float passing,
        Float passingPotential,
        Float shooting,
        Float shootingPotential,
        Float dribbling,
        Float dribblingPotential
    ) {
        Stat passStat = FootballPlayer.stats.get(FootballPlayer.Stats.PASSING);
        Stat shootStat = FootballPlayer.stats.get(FootballPlayer.Stats.SHOOTING);
        Stat dribblingStat = FootballPlayer.stats.get(FootballPlayer.Stats.DRIBBLING);

        return new FootballPlayer(
            name,
            new ArrayList<>(List.of(
                passStat.new Value(passing, passingPotential),
                shootStat.new Value(shooting, shootingPotential),
                dribblingStat.new Value(dribbling, dribblingPotential)
            ))
        );
    }

    // Creates a player that will not be valid because of missing dribbling stats
    private static FootballPlayer createInvalidPlayer(
        Float passing,
        Float passingPotential,
        Float shooting,
        Float shootingPotential
    ) {
        Stat passStat = FootballPlayer.stats.get(FootballPlayer.Stats.PASSING);
        Stat shootStat = FootballPlayer.stats.get(FootballPlayer.Stats.SHOOTING);

        return new FootballPlayer(
            "Lubo Varbanov",
            new ArrayList<>(List.of(
                passStat.new Value(passing, passingPotential),
                shootStat.new Value(shooting, shootingPotential)
            ))
        );
    }

    private static void shouldCatchException() {
        try {
            FootballPlayer p1 = createInvalidPlayer(2.3F, 3.6F, 6.7F, 12.4F);
        } catch(InputMismatchException exception) {
            System.out.println(exception.getMessage());
        }
    }

    private static void shouldBeInvalid() {
        FootballPlayer p1 = createInvalidPlayer(2.3F, 3.6F, 6.7F, 8.4F);

        if (p1.isValid()) {
            System.out.println("Player is valid");
        } else {
            System.out.println("Player is invalid");
        }
    }

    public static void main(String[] args) {
        shouldCatchException();
        shouldBeInvalid();

        Team<FootballPlayer> team = new Team<>();
        FootballPlayer player1 = createPlayer("A", 1F, 2F, 3F, 4F, 5F, 6F);
        FootballPlayer player2 = createPlayer("B", 2F, 3F, 4F, 5F, 6F, 8.2F);

        team.add(player1);
        team.add(player2);

        System.out.println(team.getFutureStars("Dribbling"));
        System.out.println(team.getWorst((a, b) -> a.getSkill("Passing").current.compareTo(b.getSkill("Passing").current)));

    }
}
