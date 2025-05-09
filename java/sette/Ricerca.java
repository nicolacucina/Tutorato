package sette;

public class Ricerca {

    private int[] numeri;

    public Ricerca(int size){
        numeri = new int[size];
        for(int i = 0; i<size; i++){
            numeri[i] = i;
        }
    }

    public boolean ricercaSequenziale(int n){
        // boolean result = false;
        for(int i = 0; i<this.numeri.length; i++){
            if(numeri[i] == n){
                // result = true;
                return true;

            }
        }
        // return result;
        return false;
    }

    public boolean ricercaBinaria(int n){ // problemi di arrotondamento
        // boolean trovato = false;
        int index = numeri.length / 2;
        int increment = numeri.length / 4;
        while(true){
            // System.out.println(index);
            if(numeri[index] == n){
                // trovato = true;
                return true;
            }
            if(increment > 1){
                if(n > numeri[index]){
                    index += increment;
                }else{
                    index -= increment;
                }
                increment = increment / 2;
            }else{
                // trovato = false;
                return false;
            }               
        }   
    }

    public boolean altraRicercaBinaria(int n){
        int left = 0;
        int right = numeri.length - 1;
        while(true){
            int m = (left + right) / 2;
            if (n == this.numeri[m]){
                return true;
            }
            
            if(n > this.numeri[m]){
                if(m+1 > this.numeri.length){
                    return false;
                }
                left = m+1;
            }else{
                if(m-1 < 0){
                    return false;
                }
                right = m-1;
            }
        }
    }
}
