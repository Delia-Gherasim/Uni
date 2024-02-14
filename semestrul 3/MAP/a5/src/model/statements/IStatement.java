package model.statements;

import model.utils.ProgrState;

public interface IStatement {
    String toString();

    ProgrState execute(ProgrState state) throws Exception;

}
