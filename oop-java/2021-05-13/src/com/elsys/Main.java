package com.elsys;

public class Main {

    public static void main(String[] args) {
        OuterClass.StaticNestedClass staticNestedInstance = new OuterClass.StaticNestedClass();

        OuterClass outerInstance = new OuterClass();
        OuterClass.InnerClass innerInstance = outerInstance.new InnerClass();

        outerInstance.testMethod();

	    Box<Integer> intbox = new Box<>();
		Box<String> strbox = new Box<>();

	    intbox.setContent(12);
	    strbox.setContent("Go6o ot po4ivka");

	    System.out.println(intbox.getContent());
		System.out.println(strbox.getContent());
    }
}
