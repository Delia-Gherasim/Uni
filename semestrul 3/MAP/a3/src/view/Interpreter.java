package view;

import controller.Controller;
import model.expresion.ArithmOp;
import model.expresion.ArithmeticExpression;
import model.expresion.ValueExpression;
import model.expresion.VariableExpression;
import model.statements.*;
import model.types.BoolType;
import model.types.IntType;
import model.types.StringType;
import model.utils.*;
import model.value.BoolValue;
import model.value.IValue;
import model.value.IntValue;
import model.value.StringValue;
import repository.IRepository;
import repository.Repository;

import java.io.BufferedReader;

public class Interpreter {
    static boolean flag=true;
    public static void main(String[] args){
        IStatement ex1 = new CompoundStatement(
                new VariableDeclarationStatement("v", new IntType()),
                new CompoundStatement(
                        new AssignmentStatement("v", new ValueExpression(new IntValue(2))),
                        new PrintStatement(new VariableExpression("v"))
                )
        );

        IStatement ex2 = new CompoundStatement(
                new VariableDeclarationStatement("a", new IntType()),
                new CompoundStatement(
                        new VariableDeclarationStatement("b", new IntType()),
                        new CompoundStatement(
                                new AssignmentStatement("a", new ArithmeticExpression(
                                        new ValueExpression(new IntValue(2)),
                                        ArithmOp.ADD,
                                        new ArithmeticExpression(
                                                new ValueExpression(new IntValue(3)),
                                                ArithmOp.MULTIPLY,
                                                new ValueExpression(new IntValue(5))
                                        )
                                )),
                                new CompoundStatement(
                                        new AssignmentStatement("b", new ArithmeticExpression(
                                                new VariableExpression("a"),
                                                ArithmOp.ADD,
                                                new ValueExpression(new IntValue(1))
                                        )),
                                        new PrintStatement(new VariableExpression("b"))
                                )
                        )
                )
        );

        IStatement ex3=new CompoundStatement(
                new VariableDeclarationStatement("a", new BoolType()),
                new CompoundStatement(
                        new VariableDeclarationStatement("v", new IntType()),
                        new CompoundStatement(
                                new AssignmentStatement("a", new ValueExpression(new BoolValue(true))),
                                new CompoundStatement(
                                        new IfStatement(
                                                new VariableExpression("a"),
                                                new AssignmentStatement("v", new ValueExpression(new IntValue(2))),
                                                new AssignmentStatement("v", new ValueExpression(new IntValue(3)))),
                                        new PrintStatement(new VariableExpression("v"))))));

        IStatement ex4 =
                new CompoundStatement(
                        new VariableDeclarationStatement("varf", new StringType()),
                        new CompoundStatement(
                                new AssignmentStatement("varf", new ValueExpression(new StringValue("C:\\Facultation\\sem3\\map\\lab\\a3\\test.in"))),
                                new CompoundStatement(
                                        new openRFile(
                                                new VariableExpression("varf")),
                                        new CompoundStatement(
                                                new VariableDeclarationStatement("varc", new IntType()),
                                                new CompoundStatement(
                                                        new readFile(
                                                                new VariableExpression("varf"),
                                                                new StringValue("varc")
                                                        ),
                                                        new CompoundStatement(
                                                                new PrintStatement(new VariableExpression("varc")),
                                                                new CompoundStatement(
                                                                        new readFile(
                                                                                new VariableExpression("varf"),
                                                                                new StringValue("varc")
                                                                        ),
                                                                        new CompoundStatement(
                                                                                new PrintStatement(new VariableExpression("varc")),
                                                                                new closeRFile(new VariableExpression("varf"))
                                                                        ))))))));

        IStack<IStatement> stk1 = new ExecuteStack<IStatement>() {};
        IStack<IStatement> stk2 = new ExecuteStack<IStatement>() {};
        IStack<IStatement> stk3 = new ExecuteStack<IStatement>() {};
        IStack<IStatement> stk4 = new ExecuteStack<IStatement>() {};
        IDictionary<String, IValue> symbolTable1 = new SymbolTable<>();
        IDictionary<String, IValue> symbolTable2 = new SymbolTable<>();
        IDictionary<String, IValue> symbolTable3 = new SymbolTable<>();
        IDictionary<String, IValue> symbolTable4 = new SymbolTable<>();
        IDictionary<IValue, BufferedReader> fileTable1=new FileTable<>();
        IDictionary<IValue, BufferedReader> fileTable2=new FileTable<>();
        IDictionary<IValue, BufferedReader> fileTable3=new FileTable<>();
        IDictionary<IValue, BufferedReader> fileTable4=new FileTable<>();
        IListoutput<IValue> out1 = new Output<IValue>();
        IListoutput<IValue> out2 = new Output<IValue>();
        IListoutput<IValue> out3 = new Output<IValue>();
        IListoutput<IValue> out4 = new Output<IValue>();
        ProgrState PrgState1 = new ProgrState(stk1, symbolTable1, out1, ex1, fileTable1);
        ProgrState PrgState2 = new ProgrState(stk2, symbolTable2, out2, ex2, fileTable2);
        ProgrState PrgState3 = new ProgrState(stk3, symbolTable3, out3, ex3, fileTable3);
        ProgrState PrgState4 = new ProgrState(stk4, symbolTable4, out4,  ex4, fileTable4);
        IRepository repo1 = new Repository("log1.txt");
        IRepository repo2 = new Repository("log2.txt");
        IRepository repo3 = new Repository("log3.txt");
        IRepository repo4 = new Repository("log4.txt");
        repo1.add(PrgState1);
        repo2.add(PrgState2);
        repo3.add(PrgState3);
        repo4.add(PrgState4);
        Controller controller1 = new Controller(repo1, flag);
        Controller controller2 = new Controller(repo2, flag);
        Controller controller3 = new Controller(repo3, flag);
        Controller controller4 = new Controller(repo4, flag);
        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1",ex1.toString(),controller1));
        menu.addCommand(new RunExample("2",ex2.toString(),controller2));
        menu.addCommand(new RunExample("3",ex3.toString(),controller3));
        menu.addCommand(new RunExample("4", ex4.toString(), controller4));
        menu.show();
    }
}
