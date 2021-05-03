import java.util.*;

public class Main {

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int K = in.nextInt();

        int maxWeight = 0;
        int[] values = new int[K + 1];
        Arrays.fill(values, -1);
        values[0] = 0;

        for (int i = 0; i < N; i++) {
            int w = in.nextInt();
            int v = in.nextInt();

            for (int weight = maxWeight; weight >= 0; weight--) {
                if (values[weight] == -1) continue;
                if (weight + w > K) continue;
                if (values[weight + w] > values[weight] + v) continue;

                values[weight + w] = values[weight] + v;
                if (weight + w > maxWeight) {
                    maxWeight = weight + w;
                }
            }
        }

        int max = 0;
        for (int v : values) {
            if (v > max) {
                max = v;
            }
        }

        System.out.println(max);
    }
}
