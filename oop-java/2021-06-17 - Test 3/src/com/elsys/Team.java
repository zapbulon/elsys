package com.elsys;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class Team<T extends Player> {
    private List<T> members = new ArrayList<>();

    void add(T player) {
        this.members.add(player);
    }

    public List<String> getFutureStars(String skillName) {
        return this.members.stream()
                .filter(p -> (float) p.getSkill(skillName).potential > 8)
                .map(p -> p.getName())
                .collect(Collectors.toList());
    }

    public T getWorst(Comparator<T> comparator) {
        return this.members.stream()
                    .min(comparator)
                    .get();
    }
}
