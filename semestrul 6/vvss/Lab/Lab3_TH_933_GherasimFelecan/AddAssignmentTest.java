package com.example;

import com.example.domain.Tema;
import com.example.repository.NotaXMLRepo;
import com.example.repository.StudentXMLRepo;
import com.example.repository.TemaXMLRepo;
import com.example.service.Service;
import com.example.validation.NotaValidator;
import com.example.validation.StudentValidator;
import com.example.validation.TemaValidator;
import com.example.validation.ValidationException;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class AddAssignmentTest {
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
    public void testInvalid_IDIsEmpty() {
        Tema tema = new Tema("", "descriere buna", 6, 7);
        Exception exception = assertThrows(ValidationException.class, () -> {
            service.addTema(tema);
        });
        assertEquals("Numar tema invalid!", exception.getMessage());
    }

    @Test
    public void testInvalid_DescriereIsEmpty() {
        Tema tema = new Tema("335", "", 6, 7);
        Exception exception = assertThrows(ValidationException.class, () -> {
            service.addTema(tema);
        });
        assertEquals("Descriere invalida!", exception.getMessage());
    }

    @Test
    public void testInvalid_DeadlineTooLow() {
        Tema tema = new Tema("334", "descriere buna", 0, 7);
        Exception exception = assertThrows(ValidationException.class, () -> {
            service.addTema(tema);
        });
        assertEquals("Deadlineul trebuie sa fie intre 1-14.", exception.getMessage());
    }

    @Test
    public void testInvalid_DeadlineTooHigh() {
        Tema tema = new Tema("333", "descriere buna", 15, 7);
        Exception exception = assertThrows(ValidationException.class, () -> {
            service.addTema(tema);
        });
        assertEquals("Deadlineul trebuie sa fie intre 1-14.", exception.getMessage());
    }

    @Test
    public void testValidTema() {
        Tema tema = new Tema("1005", "descriere buna", 10, 5);
        assertEquals(null, service.addTema(tema));
    }

    @Test
    public void testInvalid_PrimireIsBelow1() {
        Tema tema = new Tema("332", "descriere buna", 6, 0);
        Exception exception = assertThrows(ValidationException.class, () -> {
            service.addTema(tema);
        });
        assertEquals("Saptamana primirii trebuie sa fie intre 1-14.", exception.getMessage());
    }
    @Test
    public void testInvalid_PrimireIsAbove14() {
        Tema tema = new Tema("331", "descriere buna", 6, 15);
        Exception exception = assertThrows(ValidationException.class, () -> {
            service.addTema(tema);
        });
        assertEquals("Saptamana primirii trebuie sa fie intre 1-14.", exception.getMessage());
    }

    @Test
    public void testPath_IDEmpty() {
        Tema tema = new Tema("", "descriere buna", 10, 5);
        assertThrows(ValidationException.class, () -> service.addTema(tema));
    }

    @Test
    public void testPath_DescriereEmpty() {
        Tema tema = new Tema("226", "", 10, 5);
        assertThrows(ValidationException.class, () -> service.addTema(tema));
    }

    @Test
    public void testPath_DeadlineTooLow() {
        Tema tema = new Tema("225", "descriere buna", 0, 5);
        assertThrows(ValidationException.class, () -> service.addTema(tema));
    }

    @Test
    public void testPath_DeadlineTooHigh() {
        Tema tema = new Tema("224", "descriere buna", 15, 5);
        assertThrows(ValidationException.class, () -> service.addTema(tema));
    }

    @Test
    public void testPath_PrimireTooLow() {
        Tema tema = new Tema("223", "descriere buna", 10, 0);
        assertThrows(ValidationException.class, () -> service.addTema(tema));
    }

    @Test
    public void testPath_PrimireTooHigh() {
        Tema tema = new Tema("222", "descriere buna", 10, 15);
        assertThrows(ValidationException.class, () -> service.addTema(tema));
    }

    @Test
    public void testPath_AllValid() {
        Tema tema = new Tema("10009", "descriere buna", 10, 5);
        assertEquals(null, service.addTema(tema));
    }


}
