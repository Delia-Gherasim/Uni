// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import  com.asaoziindianu.*;
public class Main {
    public static void main(String[] args) {

        innebunesc a=new innebunesc();
        a.input();
        a.hello();

        base b=new base();
        b.f();
        base b2=new derived();
        b2.f();

        derived d=new derived();
        d.f();

        System.out.println(base.number);
        base.number=67;
        System.out.println(base.number);
        /*
        int suma=0;
        int i=0;
        for (String nr: args){
            int val=Integer.parseInt(nr);
            suma=val+suma;
            System.out.println(val);
            i=i+1;
        }
        i--;
        System.out.println(suma/i);*/



    }

}

