import java.util.*;

public class Main{

     public static void main(String []args){
        Scanner s = new Scanner(System.in);
        int H = s.nextInt();
        int W = s.nextInt();
        int X = s.nextInt();
        int Y = s.nextInt();
        
        int[][] originalArr = new int[H][W];
        int[][] arr = new int[H + X][W + Y];
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                arr[i][j] = s.nextInt();
            }
        }
        
        for (int i = 0; i < originalArr.length; i++) {
            for (int j = 0; j < originalArr[i].length; j++) {
                if (i < X && j < W) originalArr[i][j] = arr[i][j];
                else if (j < Y && i < H) originalArr[i][j] = arr[i][j];
                else originalArr[i][j] = arr[i][j] - originalArr[i - X][j - Y];
            }
        }
        
        for (int i = 0; i < originalArr.length; i++) {
            for (int j = 0; j < originalArr[i].length; j++) {
                System.out.print(originalArr[i][j] + " ");
            }
            System.out.println("");
        }
         
     }
}
