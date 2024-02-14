package repository;

import model.statements.ProgrState;

public interface IRepository {
    ProgrState getCurrentProgramState() throws Exception;

    void add(ProgrState programState);

    void logProgrState() throws Exception;

}
