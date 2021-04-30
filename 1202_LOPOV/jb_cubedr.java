import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        
        int N = in.nextInt();
        int K = in.nextInt();
        
        Jewel[] jewels = new Jewel[N];
        for (int i = 0; i < jewels.length; i++) {
            jewels[i] = new Jewel(in.nextInt(), in.nextInt());
        }
        Arrays.sort(jewels, (l, r) -> l.weight - r.weight);
        
        int[] bags = new int[K];
        for (int i = 0; i < bags.length; i++) {
            bags[i] = in.nextInt();
        }
        Arrays.sort(bags);
        
        long value = 0;
        int jIdx = 0;
        PriorityQueue<Jewel> pq = new PriorityQueue<>((l, r) -> r.value - l.value);
        for (int b : bags) {
            for (; jIdx < jewels.length && jewels[jIdx].weight <= b; jIdx++) {
                pq.add(jewels[jIdx]);
            }
            
            if (pq.isEmpty()) continue;
            
            value += pq.poll().value;
        }
        System.out.println(value);
    }
    
    static class Jewel {
        final int weight;
        final int value;
        
        Jewel(int weight, int value) {
            this.weight = weight;
            this.value = value;
        }
    }
}
