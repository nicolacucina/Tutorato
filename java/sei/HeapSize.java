package sei;

public class HeapSize {
    public static void main(String[] args) {
        // Estimate the Heap size of the JVM
        long heapSize = Runtime.getRuntime().totalMemory() / (1024 * 1024); // in MB
        long maxHeapSize = Runtime.getRuntime().maxMemory() / (1024 * 1024); // in MB   
        long freeHeapSize = Runtime.getRuntime().freeMemory() / (1024 * 1024); // in MB

        System.out.println("Heap Size: " + heapSize + " MB");
        System.out.println("Max Heap Size: " + maxHeapSize + " MB");
        System.out.println("Free Heap Size: " + freeHeapSize + " MB");
        System.out.println("Used Heap Size: " + (heapSize - freeHeapSize) + " MB");

        int n = 1000;
        Object array = new Object[n]; // Allocate a large array to increase heap usage
        for(int i =0; i<n; i++){
            array = new Object[i]; // Allocate a large array to increase heap usage
        }

        heapSize = Runtime.getRuntime().totalMemory() / (1024 * 1024); // in MB
        maxHeapSize = Runtime.getRuntime().maxMemory() / (1024 * 1024); // in MB   
        freeHeapSize = Runtime.getRuntime().freeMemory() / (1024 * 1024); // in MB

        System.out.println("Heap Size: " + heapSize + " MB");
        System.out.println("Max Heap Size: " + maxHeapSize + " MB");
        System.out.println("Free Heap Size: " + freeHeapSize + " MB");
        System.out.println("Used Heap Size: " + (heapSize - freeHeapSize) + " MB");
    }
}
