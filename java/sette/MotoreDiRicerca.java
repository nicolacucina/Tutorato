package sette;
import java.util.HashSet;

public class MotoreDiRicerca{
    
    private HashSet<String> paroleChiave;

    public MotoreDiRicerca(){
        this.paroleChiave = new HashSet<String>();        
    }

    public boolean aggiungiParolaChiave(String s){
        return this.paroleChiave.add(s);
    }

    public boolean isParolaChiaveUtilizzata(String s){
        return this.paroleChiave.contains(s);   
    }

    public int numeroParoleChiave(){
        return this.paroleChiave.size();
    }

    public boolean rimuoviParolaChiave(String s){
        return this.paroleChiave.remove(s);
    }

    public String toString(){
        String result = "";

        for (String s : this.paroleChiave){
            result += s;
        }
        return result;
    }

    public String toStringer(){
        return this.paroleChiave.toString();
    }

}