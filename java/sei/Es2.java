package sei;

public class Es2 {
    
    public static boolean ricorsivo(int[] numeri, boolean pari){
        if(numeri.length == 0){
            return pari;
        }else{
            int [] numeri_temp = new int[numeri.length - 1];
            for(int i = 0; i < numeri.length - 1; i++){
                numeri_temp[i] = numeri[i+1];
            }
            if(numeri[0] % 2 == 0){
                return ricorsivo(numeri_temp, true);
            }else{
                return ricorsivo(numeri_temp, false);
            }
        }
    }

    public static boolean avviaRicorsione(int[] numeri){
        if (numeri[0] % 2 == 0){
            System.out.println("Il primo numero è pari");
            return ricorsivo(numeri, true);
        }
        else{
            System.out.println("Il primo numero è dispari");
            return ricorsivo(numeri, false);

        }  
    }

    public static void main(String[] args) {
        int[] numeri = {1,4,5,10,15,6};
        boolean result = avviaRicorsione(numeri);
        System.out.println("Il risultato finale è: " + result);
    }

}
