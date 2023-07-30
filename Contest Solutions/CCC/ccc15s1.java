import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int k = scanner.nextInt(), total = 0;
        int[] n = new int[k];
        
        for (int i = 0; i < k; i++) {
            n[i] = scanner.nextInt();
            if (n[i] == 0) {
                k -= 2;
                n[i - 1] = 0;
                i -= 2;
            }
        }
        
        for (int i : n) {
            total += i;
        }
        
        System.out.println(total);
    }
}
