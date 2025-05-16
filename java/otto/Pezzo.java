package otto;

public class Pezzo {
    /*
     * R    D       A       C       T       P 
     * re   donna   alfiere cavallo torre   pedone
     */
    public final static char RE = 'R';
    public final static char DONNA = 'D';
    public final static char ALFIERE = 'A';
    public final static char CAVALLO = 'c';
    public final static char TORRE = 'T';
    public final static char PEDONE = 'P';
    
    public final static char BIANCO = 'B';
    public final static char NERO = 'N';

    private char tipo; // indica il tipo di pezzo secondo quanto indicato in tabella 
    private char colore; // B=bianco, N=nero 
    
    public Pezzo(char t, char c){ 
        tipo=t; 
        colore=c; 
    } 
    
    public char getTipo(){ return tipo; } 
    
    public char getColore(){ return colore; }
}
