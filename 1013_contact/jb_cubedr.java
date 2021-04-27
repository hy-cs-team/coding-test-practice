import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while (T-- > 0) {
            if (in.next().matches("(100+1+|01)+")) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
