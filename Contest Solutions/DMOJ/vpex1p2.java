import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), sum = 0, count = 0;
        int[] x = new int[n];
        
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
            sum += x[i];
        }
        
        for (int i = 0; i < n; i++) {
            if (x[i] != sum/n) {
                count++;
            }
        }
        
        System.out.println(count);
    }
}
