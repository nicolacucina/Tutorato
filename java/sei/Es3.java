package sei;

public class Es3 {

    public static String ricorsivo(String s, int index){
        if(index >= s.length()){
            return "";
        }else{
            return s.charAt(index) + ricorsivo(s, index + 2);
        }
    }
        

    public static String avviaRicorsione(String s){
        return ricorsivo(s, 0);
    }
    public static void main(String[] args) {
        String s = "programmazione";
        String result = avviaRicorsione(s);
        System.out.println(result);
    }
}
