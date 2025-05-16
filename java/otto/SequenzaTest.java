package otto;
import fond.io.*;

public class SequenzaTest {

    public static void tester(){
                String[] a = {"1001001", "110", "01100"};
        SequenzaDiStringheBinarie test = new SequenzaDiStringheBinarie(a);
        System.out.println(test.valoreStringa(0));
        int[] result = test.elementiSopraSoglia(10);
        for(int i : result){
            System.out.println(i);
        }
        System.out.println(test);
    }
    public static void main(String[] args) {
        SequenzaTest.tester();
        InputWindow in = new InputWindow();
        int size = in.readInt("inserire dimensione array");
        String[] inputs = new String[size];
        for(int i=0; i<size; i++){
            String s = in.readString("inserire stringa binaria");
            if(!s.contains("0") && !s.contains("1")){
                throw new IllegalArgumentException("inserire una stringa binaria");
            }
            inputs[i] = s;
        }
        System.out.println(inputs);
    }
}
