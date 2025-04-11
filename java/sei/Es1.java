package sei;

public class Es1 {
    public static int restoRicorsivo(int n, int m){
        if(n < m){
            return n;
        }else{
            return Es1.restoRicorsivo(n - m, m);
        }
    }

    public static void main(String[] args){
        int n = 11;
        int m = 3;
        System.out.println("Il resto di " + n + " diviso " + m + " è: " + Es1.restoRicorsivo(n, m));
    }
}
