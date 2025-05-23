package esami.B;

public class ProvaInsiemeDiParole {
    
    public static void testMetodi(){
        String[] s = {
            "Palletta",
            "Cinguettii", 
            "Appallottolare", 
            "Alba", 
            "PASsero"};
        InsiemeDiParole p = new InsiemeDiParole(s);
        int[] result = p.contaDoppiePerParola();
        for(int i = 0; i< result.length; i++){
            System.out.println(result[i]);
        }
        
        InsiemeDiParole pp = p.rimuoviParoleCorte(5);
        System.out.println(p);
        System.out.println(pp);
    }
    
    public static void main(String[] args) {
        testMetodi();
    }
}
