package com.elsys;

// If we want to specify an interface to be obeyed by the types provided in the <>
// we use the keyword "extends"
public class Box<T /* extends CustomInterface*/ > {
    T content;

    T getContent() {
        return this.content;
    }

    void setContent(T t) {
        this.content = t;
    }
}
