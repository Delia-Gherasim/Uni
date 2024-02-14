package view;

import controller.Controller;
import exception.CustomException;
import exception.ItemNotFound;
import model.Bicicleta;
import model.Masina;
import model.Motocicleta;

import java.util.InputMismatchException;
import java.util.Scanner;

public class View {
    Controller contr;

    public View(Controller controller) {
        this.contr = controller;
    }

    public void printMenu() {
        System.out.println("0. Exit");
        System.out.println("1. Add a car, motorcycle or a bike");
        System.out.println("2. Remove an item from the list");
        System.out.println("3. See only the red automobiles");
        System.out.println("4. See all");

    }

    public void addItemInterface() throws CustomException {
        System.out.println("What type of item would you like to add?");
        System.out.println("1.Car");
        System.out.println("2.Motorcycle");
        System.out.println("3.Bicycle");
        Scanner scanner = new Scanner(System.in);
        int option;
        try {
            option = scanner.nextInt();
        } catch (InputMismatchException e) {
            System.out.println("Custom Exception caught: Please input an integer");
            return;
        }

        if (option < 1 || option > 3) {
            System.out.println("Invalid option");
            return;
        }
        System.out.println("What color is it?");
        String color = scanner.next();

        if (option == 1)

            this.contr.addItem(new Masina(color));
        else if (option == 2) {

            this.contr.addItem(new Motocicleta(color));
        } else if (option == 3) {
            this.contr.addItem(new Bicicleta(color));
        } else {
            System.out.println("Invalid option. No item was added.");
        }
        System.out.println("Ok, it was added");
    }

    public void removeItemInterface() throws ItemNotFound {
        System.out.println("What type of item would you like to remove?");
        System.out.println("1.Car");
        System.out.println("2.Motorcycle");
        System.out.println("3.Bicycle");
        Scanner scanner = new Scanner(System.in);
        int option;
        try {
            option = scanner.nextInt();
        } catch (InputMismatchException e) {
            System.out.println("Custom Exception caught: Please input an integer");
            return;
        }
        if (option < 1 || option > 3) {
            System.out.println("Invalid option");
            return;
        }
        System.out.println("What color is it?");
        String color = scanner.next();
        if (option == 1)

            this.contr.removeItem(new Masina(color));

        else if (option == 2) {

            this.contr.removeItem(new Motocicleta(color));

        } else if (option == 3) {

            this.contr.removeItem(new Bicicleta(color));

        }

        System.out.println("Ok, it was removed");
    }

    public void run() {
        printMenu();
        Scanner scanner = new Scanner(System.in);
        System.out.println("what option do you choose? ");
        int option;
        try {
            option = scanner.nextInt();
        } catch (InputMismatchException e) {
            System.out.println("Custom Exception caught: Please input an integer");
            return;
        }
        while (option != 0) {
            try {
                if (option == 1)
                    addItemInterface();
                else if (option == 2) {
                    removeItemInterface();
                } else if (option == 3) {
                    if (this.contr.getFilteredSize() == 0) {
                        System.out.println("There are none ");
                    } else {
                        for (int i = 0; i < this.contr.getFilteredSize(); i++)
                            System.out.println(this.contr.getFiltered()[i].toString());
                    }

                } else if (option == 4) {
                    for (int i = 0; i < this.contr.getSize(); i++)
                        System.out.println(this.contr.getAll()[i].toString());
                } else {
                    System.out.println("Invalid option");
                }
                printMenu();
                System.out.println("what option do you choose? ");

                option = scanner.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Custom Exception caught: Please input an integer");
                return;
            } catch (CustomException | ItemNotFound ex) {
                System.out.println(ex.getMessage());
            }


        }
    }
}
