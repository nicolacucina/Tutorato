package sette;

public class TestMax {
    public static int[] calcolaMassimi(int[] a){
        int max[] = new int[a.length];
        
        for(int i=0;i<max.length;i++){
            max[i]=a[0];
            for(int j=1;j<=i;j++){
                if(a[j]>max[i]){
                    max[i]=a[j];
                }
            }
                
        }
        return max;
    }
    public static int[] calcolaMassimi2(int[] a){
        int max[] = new int[a.length];
        max[0]=a[0];
        for(int i=1;i<max.length;i++){
            if(a[i]>max[i-1]){
                max[i]=a[i];
            }
            else{
                max[i]=max[i-1];
            }
        }
        return max;
    }
    public static String printArray(int[] a){
        String s = "[";
        for (int i = 0; i<a.length-1; i++){
            s+=a[i] + ",";
        }
        s+=a[a.length-1] + "]";
        return s;
    }
    public static void main(String[] args) {
        int a[] = {1, 7, 12, 11, 14, 15, 64, 5, 2, 30, 20, 25, 105};
        int algoritmo1[] = calcolaMassimi(a);
        int algoritmo2[] = calcolaMassimi(calcolaMassimi2(a));
        System.out.println("Algoritmo 1: " + printArray(algoritmo1));
        System.out.println("Algoritmo 2: " + printArray(algoritmo2));
    }
}
