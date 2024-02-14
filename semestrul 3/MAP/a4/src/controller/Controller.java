package controller;

import model.exceptions.ExceptionStack;
import model.statements.IStatement;
import model.statements.ProgrState;
import model.utils.IHeap;
import model.utils.IListoutput;
import model.utils.IStack;
import model.utils.SymbolTable;
import model.value.IValue;
import model.value.RefValue;
import repository.IRepository;

import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;

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
        if (stk.isEmpty())
            throw new ExceptionStack("programstate stack is empty");
        IStatement crtStmt = stk.pop();
        return crtStmt.execute(state);
    }

    public void allStepFile() throws Exception {
        ProgrState prg = repo.getCurrentProgramState();
        repo.logProgrState();
        if (flag) {
            while (!prg.getExeStack().isEmpty()) {
                oneStep(prg);
                repo.logProgrState();
                prg.getHeap().setContent(unsafeGarbageCollector(getAddrFromSymbTable(prg.getSymTable().getContent().values()),getAddrFromSymbTable(prg.getHeap().getContent().values()),prg.getHeap().getContent()));
                repo.logProgrState();

            }
        }
        if (!flag) {
            repo.logProgrState();
        }
        repo.logProgrState();
        IListoutput<IValue> out = repo.getCurrentProgramState().getOut();
        System.out.println(out.toString());
    }

    Map<Integer,IValue> unsafeGarbageCollector(List<Integer> symTableAddr, List<Integer> heapAddr, Map<Integer, IValue> heap){
        return heap.entrySet().stream()
                .filter(e->symTableAddr.contains(e.getKey())||heapAddr.contains(e.getKey()))
                        .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));}

    List<Integer> getAddrFromSymbTable(Collection<IValue> symbTableValues){
        return symbTableValues.stream().filter(v->v instanceof RefValue)
                .map(v->{RefValue v1=(RefValue) v;
                    return v1.getAddress();})
                .collect(Collectors.toList());
    }


}
