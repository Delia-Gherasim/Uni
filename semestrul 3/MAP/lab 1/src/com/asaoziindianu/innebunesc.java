package com.asaoziindianu;

import java.util.Scanner;

public class innebunesc {
    int number;
    String name;
    private int cnp;

    public innebunesc(){
        number=120;
        name="ia.ma doamne";
    }

    public void input(){
        Scanner scanner=new Scanner(System.in);
        System.out.print("What is your name? ");
        name= scanner.nextLine();
    }

    public void hello()
    {
        System.out.println("hello "+name);
    }
}
