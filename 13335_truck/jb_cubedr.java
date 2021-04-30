import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();
        int w = in.nextInt();
        int L = in.nextInt();
        
        int[] trucks = new int[n];
        for (int i = 0; i < n; i++) {
            trucks[i] = in.nextInt();
        }
        
        int tIdx = 0;
        int loads = 0;
        int time = 0;
        int on = 0;
        
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < w; i++) {
            q.add(0);
        }
        while (tIdx < n) {
            int out = q.poll();
            loads -= out;
            if (out > 0) on--;
            
            if (loads + trucks[tIdx] <= L) {
                loads += trucks[tIdx];
                q.add(trucks[tIdx++]);
                on++;
            } else {
                q.add(0);
            }
            time++;
        }
        while (on > 0) {
            if (q.poll() > 0) on--;
            time++;
        }
        System.out.println(time);
    }
}
