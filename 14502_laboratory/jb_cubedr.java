import java.util.*;

public class Main {
    private static final int[] dx = {0, 0, -1, 1};
    private static final int[] dy = {-1, 1, 0, 0};
    
    private static int countSafeArea(int[][] map, int N, int M, List<Point> starts) {
        boolean[][] visited = new boolean[N][M];
        
        Queue<Point> q = new LinkedList<>();
        for (Point p : starts) {
            q.add(p);
            visited[p.y][p.x] = true;
        }
        
        while (!q.isEmpty()) {
            Point c = q.poll();
            
            for (int d = 0; d < 4; d++) {
                int x = c.x + dx[d];
                int y = c.y + dy[d];
                
                if (x < 0 || x >= M || y < 0 || y >= N) continue;
                if (visited[y][x] || map[y][x] != 0) continue;
                q.add(new Point(x, y));
                visited[y][x] = true;
            }
        }
        
        int count = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (visited[y][x] || map[y][x] != 0) continue;
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int M = in.nextInt();
        
        int[][] map = new int[N][M];
        List<Point> starts = new ArrayList<>();
        List<Point> empties = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j] = in.nextInt();
                
                if (map[i][j] == 0) {
                    empties.add(new Point(j, i));
                } else if (map[i][j] == 2) {
                    starts.add(new Point(j, i));
                }
            }
        }
        
        int maxSafeArea = 0;
        for (int i = 0; i < empties.size() - 2; i++) {
            Point p1 = empties.get(i);
            map[p1.y][p1.x] = 1;
            for (int j = i + 1; j < empties.size() - 1; j++) {
                Point p2 = empties.get(j);
                map[p2.y][p2.x] = 1;
                for (int k = j + 1; k < empties.size(); k++) {
                    Point p3 = empties.get(k);
                    map[p3.y][p3.x] = 1;
                    
                    int safeArea = countSafeArea(map, N, M, starts);
                    if (safeArea > maxSafeArea) maxSafeArea = safeArea;
                    
                    map[p3.y][p3.x] = 0;
                }
                map[p2.y][p2.x] = 0;
            }
            map[p1.y][p1.x] = 0;
        }
        
        System.out.println(maxSafeArea);
    }
    
    static class Point {
        final int x;
        final int y;
        
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
