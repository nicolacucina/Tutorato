package esami.e;

import java.util.HashMap;
import java.util.Map;

public class Sudoku {
    private int[][] schema;

    public Sudoku(int[][] m){
        this.schema = new int[9][9];

        for(int i = 0; i < m.length; i++){
            for(int j = 0; j < m[i].length; j++){
                /*
                 * Tipi primitivi non possono essere null, nel caso di
                 * un intero sarebbe inizializzato a 0, ma dato che è un valore valido
                 * si usa un valore negativo
                 */
                this.schema[i][j] = m[i][j];
            }
        }
    }

    private boolean controllaDoppioni(HashMap<Integer, Integer> t){
        for (Integer value : t.values()) {
            if(value != 1){
                return false;
            }
        }
        
        for (Integer key : t.keySet()) {
            if(t.get(key) != 1){
                return false;
            }
        }

        for (Map.Entry<Integer, Integer> entry : t.entrySet()) {
            if(entry.getValue() != 1){
                return false;
            }
        }

        return true;
    }

    /* Verifica se i numeri presenti sulla riga r dello schema (che può 
    contenere anche celle vuote) rispettano le regole del Sudoku.  */ 
    private boolean controllaRiga(int r){
        HashMap<Integer, Integer> temp = new HashMap<Integer, Integer>();
        
        /*
         * Voglio contare tutte le volte che incontro un numero.
         * Usare una Map è un po' un overkill per quello che vogliamo fare.
         */
        for(int i= 0; i < this.schema.length; i++){
            if(this.schema[r][i] == -1){
                continue;
            }

            if(temp.containsKey(this.schema[r][i])){
                temp.put(this.schema[r][i], temp.get(this.schema[r][i]) + 1);
            }else{
                temp.put(this.schema[r][i], 1);
            }
        }

        // for (Integer key : temp.keySet()) {
        //     System.out.println(key + " " + temp.get(key));
        // }
        // System.out.println(controllaDoppioni(temp));
        return controllaDoppioni(temp); 
    }

    /* Verifica se i numeri presenti sulla colonna c dello schema (che 
    può contenere anche celle vuote) rispettano le regole del Sudoku.*/ 
    private boolean controllaColonna(int c){
        HashMap<Integer, Integer> temp = new HashMap<Integer, Integer>();
        
        for(int i= 0; i < this.schema.length; i++){
            if(this.schema[i][c] == -1){
                continue;
            }

            if(temp.containsKey(this.schema[i][c])){
                temp.put(this.schema[i][c], temp.get(this.schema[i][c]) + 1);
            }else{
                temp.put(this.schema[i][c], 1);
            }
        }

        // for (Integer key : temp.keySet()) {
        //     System.out.println(key + " " + temp.get(key));
        // }
        // System.out.println(controllaDoppioni(temp));
        return controllaDoppioni(temp); 
    }

    /* Verifica se i numeri presenti nella regione (r,c) (che può 
    contenere anche celle vuote) rispettano le regole del Sudoku.  */ 
    private boolean controllaRegione(int r, int c){
        HashMap<Integer, Integer> temp = new HashMap<Integer, Integer>();

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(this.schema[i][j] == -1){
                continue;
                }

                if(temp.containsKey(this.schema[i][j])){
                    temp.put(this.schema[i][j], temp.get(this.schema[i][j]) + 1);
                }else{
                    temp.put(this.schema[i][j], 1);
                }
            }
        }
        
        // for (Integer key : temp.keySet()) {
        //     System.out.println(key + " " + temp.get(key));
        // }
        // System.out.println(controllaDoppioni(temp));
        return controllaDoppioni(temp); 
    }

    /* Aggiunge il numero n allo schema nella cella (i,j). Il numero n 
    può essere aggiunto soltanto se la cella (i,j) è vuota (cioè 
    contiene il valore -1) e se la sua introduzione non viola le regole 
    del sudoku. A tal fine si tenga presente che la cella (i,j) 
    appartiene alla regione (h,k) con h=(i/3)*3 e k=(j/3)*3. Se 
    l’inserimento è valido e quindi viene effettuato, il metodo 
    restituisce true, altrimenti restituisce false */ 
    public boolean aggiungi(int i,int j, int n){       
        if(this.schema[i][j] != -1){
            return false;
        }

        this.schema[i][j] = n;
        if(
            controllaRiga(i) &&
            controllaColonna(j) &&
            controllaRegione((i/3)*3, (j/3)*3)
        ){
            return true;
        }else{
            System.out.println("revert");
           this.schema[i][j] = -1;
           return false;
        }
    }

    public String toString(){
        String s = "";
        s+="_________________\n";
        for(int i = 0; i < this.schema.length; i++){
            s+= "|";
            for(int j = 0; j < this.schema[i].length; j++){
                if(this.schema[i][j] != -1){
                    s += this.schema[i][j] + "|";
                }else{
                    s += " |";
                }
            }
            s += "\n";
        }
        s+="-----------------";
        return s;
    }
}
