import java.util.*;

public class Main {
    private static void copyArea(int[][] A, int[][] B, int rs, int re, int cs, int ce, int ro, int co) {
        for (int r = rs; r < re; r++) {
            for (int c = cs; c < ce; c++) {
                A[r][c] = B[r + ro][c + co];
            }
        }
    }
    
    private static void fillSafeArea(int[][] A, int[][] B, int H, int W, int X, int Y) {
        copyArea(A, B, 0, X, 0, W, 0, 0);
        copyArea(A, B, H - X, H, 0, W, X, Y);
        copyArea(A, B, 0, H, 0, Y, 0, 0);
        copyArea(A, B, 0, H, W - Y, W, X, Y);
    }
    
    private static void fillOverlappedArea(int[][] A, int[][] B, int H, int W, int X, int Y) {
        for (int r = X; r < H - X; r++) {
            for (int c = Y; c < W - Y; c++) {
                A[r][c] = B[r][c] - A[r - X][c - Y];
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int H = in.nextInt();
        int W = in.nextInt();
        int X = in.nextInt();
        int Y = in.nextInt();
        int[][] B = new int[H + X][W + Y];
        for (int i = 0; i < H + X; i++) {
            for (int j = 0; j < W + Y; j++) {
                B[i][j] = in.nextInt();
            }
        }
        
        int[][] A = new int[H][W];
        for (int[] r : A) Arrays.fill(r, -1);
        
        fillSafeArea(A, B, H, W, X, Y);
        fillOverlappedArea(A, B, H, W, X, Y);
        
        for (int[] r : A) {
            for (int e : r) {
                System.out.print(e + " ");
            }
            System.out.println();
        }
    }
}
