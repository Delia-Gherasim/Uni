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
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

import java.time.LocalDate;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.mockito.Mockito.*;

public class MockitoIntegration {

    StudentValidator studentValidator;
    TemaValidator temaValidator;
    NotaValidator notaValidator;

    StudentXMLRepo mockStudentRepo;
    TemaXMLRepo mockTemaRepo;
    NotaXMLRepo notaXMLRepo;

    Service service;

    @BeforeEach
    public void setup() {
        mockStudentRepo = mock(StudentXMLRepo.class);
        mockTemaRepo = mock(TemaXMLRepo.class);
        notaXMLRepo = new NotaXMLRepo("fisiere/Note.xml");

        studentValidator = new StudentValidator();
        temaValidator = new TemaValidator();
        notaValidator = new NotaValidator(mockStudentRepo, mockTemaRepo);

        service = new Service(mockStudentRepo, studentValidator, mockTemaRepo, temaValidator, notaXMLRepo, notaValidator);
    }

    @Test
    public void testAddStudent_Unit() {
        Student student = new Student("100", "John Doe", 931, "john@example.com");

        when(mockStudentRepo.findOne("100")).thenReturn(null);
        when(mockStudentRepo.save(student)).thenReturn(null);

        assertEquals(null, service.addStudent(student));

        verify(mockStudentRepo).save(student);
    }

    @Test
    public void testAddAssignment_Integration_AddStudentThenAssignment() {
        Student student = new Student("101", "Alice Pop", 934, "alice@example.com");
        Tema tema = new Tema("T1", "description", 10, 8);

        when(mockStudentRepo.findOne("101")).thenReturn(null);
        when(mockStudentRepo.save(student)).thenReturn(null);
        when(mockTemaRepo.findOne("T1")).thenReturn(null);
        when(mockTemaRepo.save(tema)).thenReturn(null);

        service.addStudent(student);
        assertEquals(null, service.addTema(tema));

        verify(mockStudentRepo).save(student);
        verify(mockTemaRepo).save(tema);
    }

    @Test
    public void testAddGrade_Integration_AddStudentAssignmentGrade() {
        Student student = new Student("102", "George Ionescu", 932, "george@example.com");
        Tema tema = new Tema("T2", "do your job", 7, 6);
        LocalDate deadlineDate = Curent.getStartDate().plusWeeks(7);
        Nota nota = new Nota("N1", "102", "T2", 10, deadlineDate);

        when(mockStudentRepo.findOne("102")).thenReturn(student);
        when(mockStudentRepo.save(student)).thenReturn(null);

        when(mockTemaRepo.findOne("T2")).thenReturn(tema);
        when(mockTemaRepo.save(tema)).thenReturn(null);

        service.addStudent(student);
        service.addTema(tema);
        assertEquals(10.0f, service.addNota(nota, "all good"));

        verify(mockStudentRepo).save(student);
        verify(mockTemaRepo).save(tema);
    }

}
