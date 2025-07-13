package com.example;

import com.example.curent.Curent;
import com.example.domain.Nota;
import com.example.domain.Student;
import com.example.domain.Tema;
import com.example.repository.NotaXMLRepo;
import com.example.repository.StudentXMLRepo;
import com.example.repository.TemaXMLRepo;
import com.example.service.Service;
import com.example.validation.NotaValidator;
import com.example.validation.StudentValidator;
import com.example.validation.TemaValidator;
import org.junit.jupiter.api.Test;

import java.time.LocalDate;
import java.time.LocalDateTime;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class BigBangTest {
    StudentValidator studentValidator = new StudentValidator();
    TemaValidator temaValidator = new TemaValidator();
    String filenameStudent = "fisiere/Studenti.xml";
    String filenameTema = "fisiere/Teme.xml";
    String filenameNota = "fisiere/Note.xml";
    StudentXMLRepo studentXMLRepository = new StudentXMLRepo(filenameStudent);
    TemaXMLRepo temaXMLRepository = new TemaXMLRepo(filenameTema);
    NotaValidator notaValidator = new NotaValidator(studentXMLRepository, temaXMLRepository);
    NotaXMLRepo notaXMLRepository = new NotaXMLRepo(filenameNota);
    Service service = new Service(studentXMLRepository, studentValidator, temaXMLRepository, temaValidator, notaXMLRepository, notaValidator);
    @Test
    public void testAddStudent() {
        Student student = new Student("12348881", "Ana Popescu", 456, "ana@yahoo.com");
        assertEquals(null,service.addStudent(student));
    }

    @Test
    public void testAddAsignment() {
        Tema tema = new Tema("6942088812", "descriere buna", 10, 10);
        assertEquals(null, service.addTema(tema));
    }

    @Test
    public void testAddGrade(){
        LocalDate deadlineDate = Curent.getStartDate().plusWeeks(7);
        Nota nota = new Nota("9999588812", "marichan", "5", 9, deadlineDate);
        assertEquals(9.0f, service.addNota(nota, "super"));
    }

    @Test
    public void testBigBang()
    {
        Student student = new Student("del88812", "Delia Gherasy", 456, "dgherasi@yahoo.com");
        service.addStudent(student);
        LocalDate deadlineDate = Curent.getStartDate().plusWeeks(7);
        Tema tema = new Tema("6666666688812", "te rog fa ti tema", 7, 6);
        service.addTema(tema);
        Nota nota = new Nota("99999988812", "del88812", "6666666688812", 2, deadlineDate);
        assertEquals(2.0, service.addNota(nota, "nu a trecut"));


    }
}
