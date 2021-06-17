package com.elsys;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FootballPlayer extends Player {
    public enum Stats {
        PASSING,
        SHOOTING,
        DRIBBLING,
    }

    static Map<Stats, Stat<Float>> stats = new HashMap<>(Map.of(
            Stats.PASSING, new Stat<>("Passing", 10F),
            Stats.SHOOTING, new Stat<>("Shooting",10F),
            Stats.DRIBBLING, new Stat<>("Dribbling",10F)
    ));

    public FootballPlayer(String name, List<Stat.Value> skills) {
        super(name, skills);
    }

    boolean isValid() {
        return this.stats.values().stream()
                .map(stat -> this.getSkill(stat.name))
                .filter(s -> s != null)
                .count() == this.stats.size();
    }
}