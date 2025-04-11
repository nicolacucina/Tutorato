package sei;

public class Es4 {

    public static boolean ricorsivo(int n){
        if(n == 1){
            return true;
        }else if(n % 2 != 0){
            return false;
        }else{
            return ricorsivo(n / 2);
        }
    }

    public static boolean ricorsivoGenerico(int n, int base){
        if(n == 1){
            return true;
        }else if(n % base != 0){
            return false;
        }else{
            return ricorsivoGenerico(n / base, base);
        }
    }

    public static void main(String[] args) {
        boolean result = ricorsivo(16);
        if(result){
            System.out.println("Il numero è una potenza di 2");
        }else{
            System.out.println("Il numero non è una potenza di 2");
        }

        int base = 4;
        result = ricorsivoGenerico(30, base);
        if(result){
            System.out.println("Il numero è una potenza di " + base);
        }else{
            System.out.println("Il numero non è una potenza di " + base);
        }
    }
}
