import java.util.*;

public class Main {
    
    private static int[] dx = {0, 0, -1, 1};
    private static int[] dy = {-1, 1, 0, 0};
    private static boolean isAdjacentToBomb(char[][] map, int r, int c) {
        if (map[r][c] == 'O') return true;
        for (int d = 0; d < 4; d++) {
            int x = c + dx[d];
            int y = r + dy[d];
            if (y < 0 || y >= map.length || x < 0 || x >= map[y].length) continue;
            if (map[y][x] == 'O') return true;
        }
        return false;
    }
    
    private static char[][] next(char[][] map) {
        char[][] reverted = new char[map.length][map[0].length];
        for (int r = 0; r < map.length; r++) {
            for (int c = 0; c < map[0].length; c++) {
                reverted[r][c] = isAdjacentToBomb(map, r, c) ? '.' : 'O';
            }
        }
        return reverted;
    }
    
    private static char[][] full(char[][] map) {
        char[][] full = new char[map.length][map[0].length];
        for (int r = 0; r < map.length; r++) {
            for (int c = 0; c < map[0].length; c++) {
                full[r][c] = 'O';
            }
        }
        return full;
    }
    
    private static void printMap(char[][] map) {
        for (char[] row : map) System.out.println(row);
    }
    
	public static void main(String[] args) {
	    Scanner in = new Scanner(System.in);
	    int R = in.nextInt();
	    int C = in.nextInt();
	    int N = in.nextInt() - 1;
	    
	    char[][] initial = new char[R][];
	    for (int r = 0; r < R; r++) {
	        initial[r] = in.next().toCharArray();
	    }
	    char[][][] cycle = new char[][][] {
	        next(next(initial)),
	        next(initial)
	    };
	    char[][] full = full(initial);
	    
	    if (N == 0) {
	        printMap(initial);
	    } else if (N % 2 == 0) {
	        printMap(cycle[(N / 2) % 2]);
	    } else {
	        printMap(full);
	    }
	}
}
