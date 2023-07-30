import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt(), n, k, a, c;
        
        for (int i = 0; i < t; i++) {
            c = 0;
            a = 0;
            n = scanner.nextInt();
            k = scanner.nextInt();
            for (int j = 0; j < n; j++) {
                a += scanner.nextInt();
                if (a >= k) {
                    c++;
                    a = 0;
                }
            }
            System.out.println(c);
        }
    }
}
