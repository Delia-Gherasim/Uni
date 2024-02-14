package model.statements;

public interface IStatement {
    String toString();

    ProgrState execute(ProgrState state) throws Exception;

}
