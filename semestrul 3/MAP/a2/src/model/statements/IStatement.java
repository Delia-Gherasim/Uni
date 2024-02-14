package model.statements;

public interface IStatement {
    public String toString();
    ProgrState execute(ProgrState state) throws Exception;

}
