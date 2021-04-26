import java.util.*;

public class Main {
    
    private static int[] dx = {0, 0, -1, 1};
    private static int[] dy = {-1, 1, 0, 0};
    private static void markExploded(boolean[][] exploded, int r, int c) {
        exploded[r][c] = true;
        
        for (int d = 0; d < 4; d++) {
            int x = c + dx[d];
            int y = r + dy[d];
            if (y < 0 || y >= exploded.length || x < 0 || x >= exploded[y].length) continue;
            exploded[y][x] = true;
        }
    }
    
    private static void pass(int[][] map, int R, int C) {
        boolean[][] exploded = new boolean[R][C];
        
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (map[r][c] > 0) {
                    if (--map[r][c] == 0) {
                        markExploded(exploded, r, c);
                    }
                }
            }
        }
        
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (exploded[r][c]) map[r][c] = 0;
            }
        }
    }
    
    private static void fill(int[][] map) {
        for (int[] row : map) {
            for (int i = 0; i < row.length; i++) {
                if (row[i] == 0) row[i] = 3;
            }
        }
    }
    
    private static void print(int[][] map) {
        for (int[] row : map) {
            for (int e : row) System.out.print(e > 0 ? 'O' : '.');
            System.out.println();
        }
    }

    public static void main(String[] args) {
	    Scanner in = new Scanner(System.in);
	    int R = in.nextInt();
	    int C = in.nextInt();
	    int N = in.nextInt() - 1;
	    
	    char[][] rawMap = new char[R][];
	    for (int r = 0; r < R; r++) {
	        rawMap[r] = in.next().toCharArray();
	    }
	    
	    int[][] map = new int[R][C];
	    for (int r = 0; r < R; r++) {
	        for (int c = 0; c < C; c++) {
	            map[r][c] = rawMap[r][c] == '.' ? 0 : 3;
	        }
	    }
	    
	    pass(map, R, C);
	    
	    for (int n = 0; n < N; n++) {
	        pass(map, R, C);
	        if (n % 2 == 0) {
	            fill(map);
	        }
	    }
	    print(map);
    }
}
