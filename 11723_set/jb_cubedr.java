import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        In in = new In();
        boolean[] s = new boolean[21];
        Arrays.fill(s, false);
        
        StringBuilder builder = new StringBuilder();
        
        int M = in.nextInt();
        for (int i = 0; i < M; i++) {
            switch (in.next()) {
            case "add":
                s[in.nextInt()] = true;
                break;
            case "check":
                builder.append(s[in.nextInt()] ? 1 : 0).append("\n");
                break;
            case "remove":
                s[in.nextInt()] = false;
                break;
            case "toggle":
                int n = in.nextInt();
                s[n] = !s[n];
                break;
            case "all":
                Arrays.fill(s, true);
                break;
            case "empty":
                Arrays.fill(s, false);
                break;
            }
        }
        System.out.println(builder.toString());
    }
    
    static class In {
        private final BufferedReader in;
        private StringTokenizer tok;
        
        In() throws IOException {
            in = new BufferedReader(new InputStreamReader(System.in));
            tok = new StringTokenizer(in.readLine());
        }
        
        String next() throws IOException {
            if (!tok.hasMoreTokens()) {
                tok = new StringTokenizer(in.readLine());
            }
            
            return tok.nextToken();
        }
        
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}
