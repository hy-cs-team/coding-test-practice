import java.util.*;

public class Main {
    
    private static int[] mem;
    private static int[] next;
    
    private static int lis(int i, int[] arr) {
        if (mem[i] != 0) return mem[i];
        
        int max = 0;
        int maxIdx = 0;
        for (int j = i + 1; j < arr.length; j++) {
            if (arr[j] <= arr[i]) continue;
            
            int l = lis(j, arr);
            if (l > max) {
                max = l;
                maxIdx = j;
            }
        }
        
        next[i] = maxIdx;
        return mem[i] = max + 1;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] arr = new int[N + 1];
        for (int i = 0; i < N; i++) {
            arr[i + 1] = in.nextInt();
        }
        mem = new int[N + 1];
        next = new int[N + 1];
        
        System.out.println(lis(0, arr) - 1);
        int i = next[0];
        do {
            System.out.print(arr[i] + " ");
            i = next[i];
        } while (i != 0);
    }
}
