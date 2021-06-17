package com.elsys;

import java.util.List;

public abstract class Player {
    String name;
    List<Stat.Value> skills;

    Player(String name, List<Stat.Value> skills) {
        this.name = name;
        this.skills = skills;
    }

    String getName() {
        return this.name;
    }

    Stat.Value getSkill(String statName) {
        return this.skills.stream()
                .reduce(null, (acc, s) -> s.getStatName() == statName ? s : acc);
    }

    abstract boolean isValid();

    @Override
    public String toString() {
        return "Player{" +
                "name='" + name + '\'' +
                ", skills=" + skills +
                '}';
    }
}
