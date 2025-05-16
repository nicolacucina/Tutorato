package otto;
import java.util.ArrayList;
import java.util.Iterator;

public class SequenzaDiStringheBinarie {
    private String[] seq; 
    
    /* crea un oggetto SequenzaDiStringheBinarie il cui contenuto è 
    rappresentato dall’array seq. Si assuma che tutte le stringhe di seq, 
    siano effettivamente stringhe binarie. */ 
    public SequenzaDiStringheBinarie (String[] seq){
        int dim = seq.length;
        this.seq = new String[dim];
        for(int i = 0; i<dim; i++){
            this.seq[i] = seq[i];
        }
    } 
    
    /* Dato un indice i restituisce il valore numerico rappresentato dalla 
    stringa binaria in posizione i se interpretata come un numero binario. Si 
    assuma che i sia un indice valido. */ 
    public int valoreStringa(int i){
        int result = 0;
        int potenza = 1;
        String temp = this.seq[i];
        while (temp.length()>0) {
            // System.out.println(result);
            // System.out.println(temp);
            // System.out.println(potenza);
            // result += (int)temp.charAt(temp.length() -1) * potenza;
            result += Integer.parseInt(String.valueOf(temp.charAt(temp.length()-1))) * potenza;
            if (potenza == 1){
                potenza += 1;
            }else{
                potenza *= 2;
            }
            temp = temp.substring(0, temp.length() -1);           
        }
        return result;
        
    } 
    
    /* Dato un intero k restituisce gli indici delle stringhe di seq il cui 
    valore (se interpretate come numeri binari) è superiore a k */     
    public int[] elementiSopraSoglia(int k){
        ArrayList<Integer> temp = new ArrayList<Integer>();
        for(int i=0; i<this.seq.length; i++){
            int n = this.valoreStringa(i);
            if (n > k){
                temp.add(i);
            }
        }

        int[] result = new int[temp.size()];
        int counter = 0;
        Iterator<Integer> i = temp.listIterator();
        while(i.hasNext()){
            result[counter] = i.next();
            counter++;
        }

        return result;
    } 

    // /* Restituisce una rappresentazione testuale della sequenza di stringhe. 
    // Per ogni elemento della sequenza va mostrata la stringa binaria e, tra 
    // parentesi, il valore numerico della stringa (se interpretata come numero 
    // binario) */ 
    public String toString(){
        String s = "";
        for(int i = 0; i < this.seq.length; i++){
            s += this.seq[i] + " (" + Integer.toString(this.valoreStringa(i)) +")\n";
        }
        return s;
    }
}
