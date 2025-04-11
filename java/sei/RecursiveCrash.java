package sei;

public class RecursiveCrash {
    public static void main(String[] args) {
        try {
            recursiveMethod(0);
        } catch (StackOverflowError e) {
            System.out.println("StackOverflowError caught: " + e.getMessage());
        }
    }

    public static void recursiveMethod(int depth) {
        // Recursive method that goes too deep
        System.out.println("Recursion depth: " + depth);

        long heapSize = Runtime.getRuntime().totalMemory() / (1024 * 1024); // in MB
        long freeHeapSize = Runtime.getRuntime().freeMemory() / (1024 * 1024); // in MB

        System.out.println("Used Heap Size: " + (heapSize - freeHeapSize) + " MB");
        recursiveMethod(depth + 1);
    }
}
