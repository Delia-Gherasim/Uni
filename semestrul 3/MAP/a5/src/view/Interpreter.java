package view;

import controller.Controller;
import model.expresion.*;
import model.statements.*;
import model.types.*;
import model.utils.*;
import model.value.*;
import repository.IRepository;
import repository.Repository;

import java.io.BufferedReader;

public class Interpreter {
    static boolean flag=true;
    public static void main(String[] args) throws Exception {
        IStatement ex1 = new CompoundStatement(
                new VariableDeclarationStatement("v", new IntType()),
                new CompoundStatement(
                        new AssignmentStatement("v", new ValueExpression(new IntValue(2))),
                        new PrintStatement(new VariableExpression("v"))));

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
                                                new ValueExpression(new IntValue(5))))),
                                new CompoundStatement(
                                        new AssignmentStatement("b", new ArithmeticExpression(
                                                new VariableExpression("a"),
                                                ArithmOp.ADD,
                                                new ValueExpression(new IntValue(1)))),
                                        new PrintStatement(new VariableExpression("b"))))));

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
                                                                new StringValue("varc")),
                                                        new CompoundStatement(
                                                                new PrintStatement(new VariableExpression("varc")),
                                                                new CompoundStatement(
                                                                        new readFile(
                                                                                new VariableExpression("varf"),
                                                                                new StringValue("varc")),
                                                                        new CompoundStatement(
                                                                                new PrintStatement(new VariableExpression("varc")),
                                                                                new closeRFile(new VariableExpression("varf"))))))))));

        IStatement ex5=new CompoundStatement(
                new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompoundStatement(
                        new New("v", new ValueExpression(new RefValue(20, new IntType()))),
                        new CompoundStatement(
                                new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompoundStatement(
                                        new New("v", new ValueExpression(new RefValue(21, new IntType()))),
                                        new CompoundStatement(
                                                new New("v", new ValueExpression(new RefValue(30, new IntType()))),
                                                new PrintStatement(new ReadHeap(new ReadHeap(new VariableExpression("a")))))))));

        IStatement ex6=new CompoundStatement(
                new VariableDeclarationStatement("v",new IntType()),
                new CompoundStatement(
                        new AssignmentStatement("v", new ValueExpression(new IntValue(4))),
                            new CompoundStatement(
                            new WhileStatement(
                                    new RelationalExpression(new VariableExpression("v"), RelationEnum.GREATER_THAN, new ValueExpression(new IntValue(0))),
                                    new CompoundStatement(
                                            new PrintStatement(new VariableExpression("v")),
                                            new AssignmentStatement("v", new ArithmeticExpression(new VariableExpression("v"), ArithmOp.MINUS, new ValueExpression(new IntValue(1)))))),
                                    new PrintStatement(new VariableExpression("v")))));

        IStatement ex7=new CompoundStatement(
                new VariableDeclarationStatement("v", new IntType()),
                new CompoundStatement(
                        new VariableDeclarationStatement("a", new RefType(new IntType())),
                        new CompoundStatement(
                                new AssignmentStatement("v", new ValueExpression(new IntValue(10))),
                                new CompoundStatement(
                                        new New("a", new ValueExpression(new RefValue(22, new IntType()))),
                                        new CompoundStatement(
                                                new ForkStatement(new CompoundStatement(
                                                        new WriteHeap("a", new ValueExpression(new RefValue(30, new RefType(new IntType())))),
                                                        new CompoundStatement(
                                                                new AssignmentStatement("v", new ValueExpression(new IntValue(32))),
                                                                new CompoundStatement(
                                                                        new PrintStatement(new VariableExpression("a")),
                                                                        new PrintStatement(new ReadHeap(new VariableExpression("a"))))))),
                                                new CompoundStatement(
                                                        new PrintStatement(new VariableExpression("v")),
                                                        new PrintStatement(new ReadHeap(new VariableExpression("a")))))))));
        IStatement ex8=new CompoundStatement(
                new VariableDeclarationStatement("counter", new IntType()),
                new CompoundStatement(
                    new VariableDeclarationStatement("a", new RefType(new IntType())),
                    new WhileStatement(
                        new RelationalExpression(new VariableExpression("counter"), RelationEnum.LESS_THAN, new ValueExpression(new IntValue(10))),
                        new CompoundStatement(
                                new ForkStatement(new ForkStatement(
                                        new CompoundStatement(
                                                new New("a", new VariableExpression("counter")),
                                                new PrintStatement(new ReadHeap(new VariableExpression("a")))))),
                                           // new VariableDeclarationStatement("a", new IntType()),
                                              //  new CompoundStatement(
                                                      //  new AssignmentStatement("a", new VariableExpression("counter")),
                                                     //   new PrintStatement(new VariableExpression("a")))))),
                                new AssignmentStatement("counter", new ArithmeticExpression(new VariableExpression("counter"), ArithmOp.ADD, new ValueExpression(new IntValue(1)))
                                )))));

        IStack<IStatement> stk1 = new ExecuteStack<IStatement>() {};
        IStack<IStatement> stk2 = new ExecuteStack<IStatement>() {};
        IStack<IStatement> stk3 = new ExecuteStack<IStatement>() {};
        IStack<IStatement> stk4 = new ExecuteStack<IStatement>() {};
        IStack<IStatement> stk5 = new ExecuteStack<IStatement>() {};
        IStack<IStatement> stk6 = new ExecuteStack<IStatement>() {};
        IStack<IStatement> stk7 = new ExecuteStack<IStatement>() {};
        IStack<IStatement> stk8 = new ExecuteStack<IStatement>(){};

        IDictionary<String, IValue> symbolTable1 = new SymbolTable<>();
        IDictionary<String, IValue> symbolTable2 = new SymbolTable<>();
        IDictionary<String, IValue> symbolTable3 = new SymbolTable<>();
        IDictionary<String, IValue> symbolTable4 = new SymbolTable<>();
        IDictionary<String, IValue> symbolTable5 = new SymbolTable<>();
        IDictionary<String, IValue> symbolTable6 = new SymbolTable<>();
        IDictionary<String, IValue> symbolTable7 = new SymbolTable<>();
        IDictionary<String, IValue> symbolTable8 = new SymbolTable<>();

        IDictionary<IValue, BufferedReader> fileTable1=new FileTable<>();
        IDictionary<IValue, BufferedReader> fileTable2=new FileTable<>();
        IDictionary<IValue, BufferedReader> fileTable3=new FileTable<>();
        IDictionary<IValue, BufferedReader> fileTable4=new FileTable<>();
        IDictionary<IValue, BufferedReader> fileTable5=new FileTable<>();
        IDictionary<IValue, BufferedReader> fileTable6=new FileTable<>();
        IDictionary<IValue, BufferedReader> fileTable7=new FileTable<>();
        IDictionary<IValue, BufferedReader> fileTable8=new FileTable<>();

        IListoutput<IValue> out1 = new Output<IValue>();
        IListoutput<IValue> out2 = new Output<IValue>();
        IListoutput<IValue> out3 = new Output<IValue>();
        IListoutput<IValue> out4 = new Output<IValue>();
        IListoutput<IValue> out5 = new Output<IValue>();
        IListoutput<IValue> out6 = new Output<IValue>();
        IListoutput<IValue> out7 = new Output<IValue>();
        IListoutput<IValue> out8 = new Output<IValue>();

        IHeap<Integer, IValue> heap1 = new Heap<>();
        IHeap<Integer, IValue> heap2 = new Heap<>();
        IHeap<Integer, IValue> heap3 = new Heap<>();
        IHeap<Integer, IValue> heap4 = new Heap<>();
        IHeap<Integer, IValue> heap5 = new Heap<>();
        IHeap<Integer, IValue> heap6 = new Heap<>();
        IHeap<Integer, IValue> heap7 = new Heap<>();
        IHeap<Integer, IValue> heap8 = new Heap<>();

        ProgrState PrgState1 = new ProgrState(stk1, symbolTable1, out1, ex1, fileTable1, heap1, 1);
        ProgrState PrgState2 = new ProgrState(stk2, symbolTable2, out2, ex2, fileTable2, heap2, 1);
        ProgrState PrgState3 = new ProgrState(stk3, symbolTable3, out3, ex3, fileTable3, heap3, 1);
        ProgrState PrgState4 = new ProgrState(stk4, symbolTable4, out4,  ex4, fileTable4, heap4, 1);
        ProgrState PrgState5 = new ProgrState(stk5, symbolTable5, out5,  ex5, fileTable5, heap5, 1);
        ProgrState PrgState6 = new ProgrState(stk6, symbolTable6, out6,  ex6, fileTable6, heap6, 1);
        ProgrState PrgState7 = new ProgrState(stk7, symbolTable7, out7,  ex7, fileTable7, heap7, 1);
        ProgrState PrgState8 = new ProgrState(stk8, symbolTable8, out8,  ex8, fileTable8, heap8, 1);

        IRepository repo1 = new Repository("log1.txt");
        IRepository repo2 = new Repository("log2.txt");
        IRepository repo3 = new Repository("log3.txt");
        IRepository repo4 = new Repository("log4.txt");
        IRepository repo5 = new Repository("log5.txt");
        IRepository repo6 = new Repository("log6.txt");
        IRepository repo7 = new Repository("log7.txt");
        IRepository repo8 = new Repository("log8.txt");

        repo1.add(PrgState1);
        repo2.add(PrgState2);
        repo3.add(PrgState3);
        repo4.add(PrgState4);
        repo5.add(PrgState5);
        repo6.add(PrgState6);
        repo7.add(PrgState7);
        repo8.add(PrgState8);

        Controller controller1 = new Controller(repo1, flag);
        Controller controller2 = new Controller(repo2, flag);
        Controller controller3 = new Controller(repo3, flag);
        Controller controller4 = new Controller(repo4, flag);
        Controller controller5 = new Controller(repo5, flag);
        Controller controller6 = new Controller(repo6, flag);
        Controller controller7 = new Controller(repo7, flag);
        Controller controller8 = new Controller(repo8, flag);

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1",ex1.toString(),controller1));
        menu.addCommand(new RunExample("2",ex2.toString(),controller2));
        menu.addCommand(new RunExample("3",ex3.toString(),controller3));
        menu.addCommand(new RunExample("4", ex4.toString(), controller4));
        menu.addCommand(new RunExample("5", ex5.toString(), controller5));
        menu.addCommand(new RunExample("6", ex6.toString(), controller6));
        menu.addCommand(new RunExample("7", ex7.toString(), controller7));
        menu.addCommand(new RunExample("8", ex8.toString(), controller8));
        menu.show();
    }
}
