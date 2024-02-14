
//1. Intr-o parcare exista masini, motociclete si biciclete.
// Sa se afiseze toate vehiculele de culoare rosie.

import controller.Controller;
import model.Bicicleta;
import model.Masina;
import model.Motocicleta;
import repository.Repository;
import repository.RepositoryInterface;
import view.View;

public class Main {
    public static void main(String[] args) {
        System.out.print("Hello and welcome!");
        RepositoryInterface repo=new Repository();
        Controller controller=new Controller(repo);
        View view=new View(controller);

//        repo.addItem(new Bicicleta("green"));
//        repo.addItem((new Motocicleta("brown")));
//        repo.addItem(new Masina("black"));
//        repo.addItem(new Masina("red"));
//        repo.addItem(new Motocicleta("blue"));
//        repo.addItem(new Masina("yellow"));
        view.run();
    }
}