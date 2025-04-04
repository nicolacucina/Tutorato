package cinque;

public class Garage {
    public static void main(String[] args) {
        Veicolo[] veicoli = new Veicolo[50];
        veicoli[0] = new Automobile("AB123CD", "Fiat Panda", 5, 5);
        veicoli[1] = new Furgone("EF456GH", "Iveco Daily", 3, 1000);
        veicoli[2] = new Automobile("IJ789KL", "Ford Fiesta", 5, 3);

        for (int i = 0; i < veicoli.length; i++) {
            if (veicoli[i] != null) {
                System.out.println(veicoli[i].toString());
            }
        }
    }
}
