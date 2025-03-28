package quattro;

public class Formicaio {
    
    public Formica[] formiche;
    public int[][] spazioOccupato;

    public Formicaio (int dim) {
        formiche = new Formica[10];

        spazioOccupato = new int[dim][dim];
        initSpazioOccupato();
    }

    private void initSpazioOccupato () {
        for (int i = 0; i < spazioOccupato.length; i++) {
            for (int j = 0; j < spazioOccupato[i].length; j++) {
                spazioOccupato[i][j] = 0;
            }
        }
    }

    private boolean occupata(int i, int j){
        if (spazioOccupato[i][j] == 0) {
            return false;
        } else {
            return true;
        }
    }

    private boolean indiciValidi(int i, int j){
        if (i < 0 || i >= spazioOccupato.length || j < 0 || j >= spazioOccupato[i].length) {
            return false;
        } else {
            return true;
        }
    }

    public boolean aggiungiFormica(int i, int j){
        Formica formica = new Formica(i, j);
        if(!occupata(i, j) && indiciValidi(i, j)) {
            formiche[Formica.getLastId() -1] = formica;
            spazioOccupato[i][j] = formica.getId();
            return true;
        } else {
            return false;
        }
    }

    private boolean idValido(int id) {
        if (id < 0 || id > Formica.getLastId()) {
            return false;
        } else {
            return true;
        }
    }

    private boolean direzioneValida(int direzione) {
        if (direzione < 1 || direzione > 4) {
            return false;
        } else {
            return true;
        }
    }

    public boolean muoviFormica(int direzione, int id){
        // 1=NORD, 2=OVEST, 3=SUD, 4=EST
        if(!idValido(id-1)){
            return false;
        }

        Formica formica = formiche[id-1];
        int i = formica.getI();
        int j = formica.getJ();

        if(!direzioneValida(direzione)){
            return false;
        }

        if(direzione == 1){
            if(i == 0){
                return false;
            }

            if(occupata(i-1, j)){
                return false;
            }

            formica.setI(i - 1);
            spazioOccupato[i][j] = 0;
            spazioOccupato[i- 1][j] = formica.getId();
            return true;

        }else if(direzione == 2){
            if(j == 0){
                return false;
            }

            if(occupata(i, j-1)){
                return false;
            }

            formica.setJ(j - 1);
            spazioOccupato[i][j] = 0;
            spazioOccupato[i][j-1] = formica.getId();
            return true;

        }else if(direzione == 3){
            if(i == spazioOccupato.length-1){
                return false;
            }

            if(occupata(i+1, j)){
                return false;
            }

            formica.setI(i + 1);
            spazioOccupato[i][j] = 0;
            spazioOccupato[i+1][j] = formica.getId();

            return true;

        }else{
            if(j == spazioOccupato[i].length-1){
                return false;
            }

            if(occupata(i, j+1)){
                return false;
            }
            
            formica.setJ(j + 1);
            spazioOccupato[i][j] = 0;
            spazioOccupato[i][j + 1] = formica.getId();

            return true;

        }
    }

    public String toString(){
        String s = "";
        for(int i=0; i<spazioOccupato.length; i++){
            for(int j=0; j<spazioOccupato[i].length; j++){
                s += spazioOccupato[i][j] + " ";
            }
            s += "\n";
        }
        return s;
    }
}
