import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt(), n, k, c;
        
        for (int i = 0; i < t; i++) {
            n = scanner.nextInt();
            k = scanner.nextInt();
            c = n/k;
            if (n%k > 0) 
                c++;
            System.out.println(c);
        }
    }
}
