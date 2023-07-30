import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[][] x = new int[2][5];
        int[] sum = new int[2], min = new int[2];
        
        for (int i = 0; i < 2; i++) {
            for (int n = 0; n < 5; n++) {
                x[i][n] = scanner.nextInt();
                min[i] = n == 0 ? x[i][n] : Math.min(min[i], x[i][n]);
                sum[i] += x[i][n];
            }
            sum[i] -= min[i];
        }
        
        System.out.println(Math.max(sum[0], sum[1]));
    }
}
