package esami.e;

public class ProvaSudoku {
    public static void main(String[] args) {
        int[][] m = {
            {5, 3, -1, -1, 7, -1, -1, -1, -1},
            {6, -1, -1, 1, 9, 5, -1, -1, -1},
            {-1, 9, 8, -1, -1, -1, -1, 6, -1},
            {8, -1, -1, -1, 6, -1, -1, -1, 3},
            {4, -1, -1, 8, -1, 3, -1, -1, 1},
            {7, -1, -1, -1, 2, -1, -1, -1, 6},
            {-1, 6, -1, -1, -1, -1, 2, 8, -1},
            {-1, -1, -1, 4, 1, 9, -1, -1, 5},
            {-1, -1, -1, -1, 8, -1, -1, 7, 9},
        };

        Sudoku s = new Sudoku(m);

        System.out.println(s.aggiungi(0, 2, 5));
        System.out.println(s);
    }
}
