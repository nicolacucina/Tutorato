package sette;

public class TestBinario {
    public static String binario(int n){
        String binario = "";
        int q = n;
        while (q>0){
            binario=(q%2)+binario;
            q = q/2;
        }
        return binario;
    }

    public static void main(String[] args) {
        int n = 51;
        System.out.println(binario(n));
    }
}
