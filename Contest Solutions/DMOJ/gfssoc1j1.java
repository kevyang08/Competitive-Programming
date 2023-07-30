import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), m = scanner.nextInt(), count = 0;
        int[] h = new int[m];
        
        for (int i = 0; i < m; i++)
            h[i] = scanner.nextInt();
            
        for (int i : h)
            if (i >= n)
                count++;
                
        System.out.println(count);
    }
}
