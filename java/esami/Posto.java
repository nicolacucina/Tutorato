package esami.g;

public class Posto {

    private char fila; 
    private int numero; 
    private int costo; 
    private boolean libero; 
    
    public Posto(char fila, int numero, int costo, boolean libero) {
        this.fila = fila;
    } 
    
    public char getFila() {
        return this.fila;
    } 
    
    public void setFila(char fila) {
        this.fila = fila;
    } 
    
    public int getNumero() {
        return this.numero;
    } 
    
    public void setNumero(int numero) {
        this.numero = numero;
    } 
    
    public int getCosto() {
        return this.costo;
    } 
    
    public void setCosto(int costo) {
        this.costo = costo;
    } 
    
    public boolean isLibero() {
        return this.libero;
    } 
    
    public void setLibero(boolean libero) {
        this.libero = libero;
    } 
    
    public String toString() {
        return "Posto "+this.fila +"-"+this.numero + ", costo: "+ this.costo + ", libero: " + this.libero;
    }     
    
}
