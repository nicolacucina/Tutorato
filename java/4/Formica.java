package quattro;

public class Formica {

    private int id;
    private int i;
    private int j;
    private static int nextId  = 1;

    public Formica (int i, int j) {
        this.i = i;
        this.j = j;
        this.id = nextId;
        nextId++;
    }

    public int getId () {
        return this.id;
    }

    public int getI () {
        return this.i;
    }

    public void setI(int i) {
        this.i = i;
    }

    public int getJ () {
        return this.j;
    }

    public void setJ(int j) {
        this.j = j;
    }
 
    public static int getLastId () {
        return Formica.nextId-1;
    }
}
