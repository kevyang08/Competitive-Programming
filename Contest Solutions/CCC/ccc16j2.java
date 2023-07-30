import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int[][] arr = new int[4][4];
        int[] sum = new int[8];
        boolean isMagic = true;
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                arr[i][j] = scanner.nextInt();
            }
        }
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                sum[i * 2] += arr[i][j];
                sum[i * 2 + 1] += arr[j][i];
            }
        }
        
        for (int i = 0; i < 7; i++) {
            if (sum[i] != sum[i + 1]) {
                isMagic = false;
            }
        }
        
        System.out.println(isMagic ? "magic" : "not magic");
    }
}
