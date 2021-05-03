import java.util.*;
import java.lang.Math;

public class Main {
    
    private static final int[] dx = {1, 0, -1, 0};
    private static final int[] dy = {0, -1, 0, 1};
    
    private static void addWalls(List<Segment> h, List<Segment> v, int L) {
        Segment lWall = new Segment(-L - 1, -L - 1, L + 1);
        Segment uWall = new Segment(L + 1, -L - 1, L + 1);
        h.add(lWall);
        h.add(uWall);
        v.add(lWall);
        v.add(uWall);
    }
    
    private static int getCollisionDistance(Segment s, List<Segment> p, int d, int x, int y) {
        int min = Integer.MAX_VALUE;
        for (Segment e : p) {
            if (s.collidesWith(e)) {
                int distance = e.distanceFrom(d, x, y);
                if (distance < min) {
                    min = distance;
                }
            }
        }
        if (min == Integer.MAX_VALUE) {
            return -1;
        }
        return min;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int L = in.nextInt();
        int N = in.nextInt();
        
        List<Segment> h = new ArrayList<Segment>();
        List<Segment> v = new ArrayList<Segment>();
        addWalls(h, v, L);
        
        int x = 0;
        int y = 0;
        int d = 0;
        long time = 0;
        Segment last = new Segment(0, 0, 0);
        for (int i = 0; i < N; i++) {
            int t = in.nextInt();
            int r = in.next().equals("R") ? 1 : -1;
            
            Segment s = Segment.fromState(d, x, y, t);
            
            int min = getCollisionDistance(s, d % 2 == 0 ? v : h, d, x, y);
            if (min != -1) {
                System.out.println(time + min);
                return;
            }
            
            if (d % 2 == 0) {
                v.add(last);
            } else {
                h.add(last);
            }
            last = s;
            
            x += t * dx[d];
            y += t * dy[d];
            d = (d + r + 4) % 4;
            time += t;
        }
        
        int min = getCollisionDistance(Segment.fromState(d, x, y, L * 3), d % 2 == 0 ? v : h, d, x, y);
        
        System.out.println(time + min);
    }
    
    static class Segment {
        final int base;
        final int start;
        final int end;
        
        Segment(int base, int start, int end) {
            this.base = base;
            
            if (start < end) {
                this.start = start;
                this.end = end;
            } else {
                this.start = end;
                this.end = start;
            }
        }
        
        boolean collidesWith(Segment p) {
            return isBetween(base, p.start, p.end) && isBetween(p.base, start, end);
        }
        
        int distanceFrom(int d, int x, int y) {
            int p = d % 2 == 0 ? x : y;
            return Math.abs(base - p);
        }
        
        static Segment fromState(int d, int x, int y, int t) {
            if (d % 2 == 0) { // 좌우
                return new Segment(y, x, x + t * dx[d]);
            } else { // 상하
                return new Segment(x, y, y + t * dy[d]);
            }
        }
        
        private static boolean isBetween(int value, int start, int end) {
            return value >= start && value <= end;
        }
    }
}
