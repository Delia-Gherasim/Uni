package com.example;

import com.example.domain.Student;


import org.junit.jupiter.api.Test;
import com.example.repository.NotaXMLRepo;
import com.example.repository.StudentXMLRepo;
import com.example.repository.TemaXMLRepo;
import com.example.service.Service;
import com.example.validation.NotaValidator;
import com.example.validation.StudentValidator;
import com.example.validation.TemaValidator;
import com.example.validation.ValidationException;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;


public class AddStudentTest {
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
    public void testValidStudent() {
        Student student = new Student("123", "Ana Popescu", 456, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }

    @Test
    public void testInvalid_NameIsEmptyString() {
        Student student = new Student("78", "", 456, "ana@yahoo.com");
        Exception exception = assertThrows(ValidationException.class, () -> {
            service.addStudent(student);
        });
        assertEquals("Nume incorect!", exception.getMessage());
    }
//    @Test
//    public void testInvalid_NameContainsSpecialCharacter() {
//        Student student = new Student("79", "@ana&Pop", 456, "ana@yahoo.com");
//        Exception exception = assertThrows(ValidationException.class, () -> {
//            service.addStudent(student);
//        });
//        assertEquals("Nume incorect!", exception.getMessage());
//    }
//    @Test
//    public void testInvalid_NameContainsNumbers() {
//        Student student = new Student("80", "ana123Pop", 456, "ana@yahoo.com");
//        Exception exception = assertThrows(ValidationException.class, () -> {
//            service.addStudent(student);
//        });
//        assertEquals("Nume incorect!", exception.getMessage());
//    }
    @Test
    public void testValid_NameContains3Character() {
        Student student = new Student("81", "A a", 456, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }
    @Test
    public void testValid_NameContains7Characters() {
        Student student = new Student("82", "Ana Pop", 456, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }
    @Test
    public void testValid_NameContainsOnlyLetters() {
        Student student = new Student("83", "Ana Popescu", 456, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }

    @Test
    public void testInvalid_IdIsEmptyString() {
        Student student = new Student("", "Ana Popescu", 456, "ana@yahoo.com");
        Exception exception = assertThrows(ValidationException.class, () -> {
            service.addStudent(student);
        });
        assertEquals("Id incorect!", exception.getMessage());
    }
//    @Test
//    public void testInvalid_IdIs0() {
//        Student student = new Student("0", "Ana Popescu", 456, "ana@yahoo.com");
//        Exception exception = assertThrows(ValidationException.class, () -> {
//            service.addStudent(student);
//        });
//        assertEquals("Id incorect!", exception.getMessage());
//    }
//    @Test
//    public void testInvalid_IdContainsSpecialCharacter() {
//        Student student = new Student("12&3", "Ana Popescu", 456, "ana@yahoo.com");
//        Exception exception = assertThrows(ValidationException.class, () -> {
//            service.addStudent(student);
//        });
//        assertEquals("Id incorect!", exception.getMessage());
//    }
//    @Test
//    public void testInvalid_IdContainsLetters() {
//        Student student = new Student("1a2B3c", "Ana Popescu", 456, "ana@yahoo.com");
//        Exception exception = assertThrows(ValidationException.class, () -> {
//            service.addStudent(student);
//        });
//        assertEquals("Id incorect!", exception.getMessage());
//    }

    @Test
    public void testValid_IdIs1Char() {
        Student student = new Student("9", "Ana Popescu", 456, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }
    @Test
    public void testValid_IdIs4Char() {
        Student student = new Student("1234", "Ana Popescu", 456, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }
    @Test
    public void testValid_IdIsOnlyNumbers() {
        Student student = new Student("123456", "Ana Popescu", 456, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }

    @Test
    public void testInvalid_GroupIsNegative() {
        Student student = new Student("82", "Ana Popescu", -1, "ana@yahoo.com");
        Exception exception = assertThrows(ValidationException.class, () -> {
            service.addStudent(student);
        });
        assertEquals("Grupa incorecta!", exception.getMessage());
    }

    @Test
    public void testValid_GroupIs1() {
        Student student = new Student("92", "Ana Popescu", 1, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }

    @Test
    public void testValid_GroupIsMaximum() {
        Student student = new Student("92", "Ana Popescu", 2147483647, "ana@yahoo.com");
        assertEquals(student, service.addStudent(student));
    }

    @Test
    public void testValid_GroupIsJustAboveMinimum() {
        Student student = new Student("93", "Ana Popescu", 2, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }
    @Test
    public void testValid_GroupIsJustBelowMaximum() {
        Student student = new Student("94", "Ana Popescu", 2147483646, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }

    @Test
    public void testValid_GroupIsNominalValue() {
        Student student = new Student("95", "Ana Popescu", 100, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }
    @Test
    public void testInvalid_EmailIsEmptyString() {
        Student student = new Student("83", "Ana Popescu", 23, "");
        Exception exception = assertThrows(ValidationException.class, () -> {
            service.addStudent(student);
        });
        assertEquals("Email incorect!", exception.getMessage());
    }

//    @Test
//    public void testInvalid_EmailMissingCharacter() {
//        Student student = new Student("84", "Ana Popescu", 23, "anayahoocom");
//        Exception exception = assertThrows(ValidationException.class, () -> {
//            service.addStudent(student);
//        });
//        assertEquals("Email incorect!", exception.getMessage());
//    }

    @Test
    public void testValid_EmailIsMaximCharacters() {
        Student student = new Student("104", "Ana Popescu", 23, "averylongemailaddresswithlotsofcharactersandrandomlettersjusttoreachthemaximumallowedlengthbeforeitgetstruncatedorinvalidbecauseRFCstandardsdefineamaximumlengthof254butwearegoingfor253whichisjustonecharlessthanthat@exampleverylongdomainnamethatkeepsongoing.com");
        assertEquals(student,service.addStudent(student));
    }

    @Test
    public void testValid_EmailMinimumValue() {
        Student student = new Student("105", "Ana Popescu", 23, "a@a.a");
        assertEquals(student,service.addStudent(student));
    }
    @Test
    public void testValid_EmailIsJustAboveMinimum() {
        Student student = new Student("106", "Ana Popescu", 23, "aa@a.a");
        assertEquals(student,service.addStudent(student));
    }

    @Test
    public void testValid_EmailIsNominalValue() {
        Student student = new Student("107", "Ana Popescu", 23, "aaaaa@aaaaaaa.a");
        assertEquals(student,service.addStudent(student));
    }

    @Test
    public void testInvalid_ProfessorNameIsEmptyString() {
        Student student = new Student("78", "", 456, "ana@yahoo.com");
        Exception exception = assertThrows(ValidationException.class, () -> {
            service.addStudent(student);
        });
        assertEquals("Nume incorect!", exception.getMessage());
    }
//    @Test
//    public void testInvalid_ProfessorNameContainsSpecialCharacter() {
//        Student student = new Student("79", "@ana&Pop", 456, "ana@yahoo.com");
//        Exception exception = assertThrows(ValidationException.class, () -> {
//            service.addStudent(student);
//        });
//        assertEquals("Nume incorect!", exception.getMessage());
//    }
//    @Test
//    public void testInvalid_ProfessorNameContainsNumbers() {
//        Student student = new Student("80", "ana123Pop", 456, "ana@yahoo.com");
//        Exception exception = assertThrows(ValidationException.class, () -> {
//            service.addStudent(student);
//        });
//        assertEquals("Nume incorect!", exception.getMessage());
//    }
    @Test
    public void testValid_ProfessorNameContains3Character() {
        Student student = new Student("81", "A a", 456, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }
    @Test
    public void testValid_ProfessorNameContains7Characters() {
        Student student = new Student("82", "Ana Pop", 456, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }
    @Test
    public void testValid_ProfesorNameContainsOnlyLetters() {
        Student student = new Student("83", "Ana Popescu", 456, "ana@yahoo.com");
        assertEquals(student,service.addStudent(student));
    }



}
