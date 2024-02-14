package view;

import controller.Controller;

public class RunExample extends Command {
    private Controller ctr;
    public RunExample(String id, String descr, Controller ctr) {
        super(id, descr);
        this.ctr=ctr;
    }

    @Override
    public void execute() {
        try{
            ctr.allStepFile();
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}
