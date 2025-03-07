import fond.io.InputWindow;
import fond.io.OutputWindow;

public class Nome {
    public static void main(String[] args) {
        InputWindow in = new InputWindow();
        String nome = in.readString();
        OutputWindow out = new OutputWindow();
        out.writeln("==========");
        out.writeln(nome);
        out.writeln("==========");
    }
}
