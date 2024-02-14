package controller;

import model.exceptions.ExceptionStack;
import model.statements.IStatement;
import model.statements.ProgrState;
import model.utils.IListoutput;
import model.utils.IStack;
import model.value.IValue;
import repository.IRepository;

public class Controller {
    IRepository repo;
    boolean flag;
    String path;
    public Controller(IRepository repo){
        this.repo=repo;
    }

    public Controller(IRepository repo, boolean flag) {
        this.repo = repo;
        this.flag = flag;
    }

    private ProgrState oneStep(ProgrState state) throws Exception {
        IStack<IStatement> stk = state.getExeStack();
        if (stk.isEmpty()) throw new ExceptionStack("programstate stack is empty");
        IStatement crtStmt = stk.pop();
        return crtStmt.execute(state);
    }

    public void allStep() throws Exception {
        ProgrState prg = repo.getCurrentProgramState();
        while (!prg.getExeStack().isEmpty()) {
            if (flag) {
                System.out.println(prg);
                System.out.println();
            }
            prg = this.oneStep(prg);
            repo.add(prg);
        }
        if (!flag) {
            IListoutput<IValue> out = repo.getCurrentProgramState().getOut();
            System.out.println(out.toString());
        }

    }

    public void allStepFile() throws Exception {
        ProgrState prg = repo.getCurrentProgramState();
       // repo.logProgrState();
        if (flag) {
            while (!prg.getExeStack().isEmpty()) {
                repo.logProgrState();

                prg = this.oneStep(prg);
                repo.add(prg);
            }
        }

        if (!flag) {
            repo.logProgrState();
        }
        repo.logProgrState();
        IListoutput<IValue> out = repo.getCurrentProgramState().getOut();
        System.out.println(out.toString());
    }

}
