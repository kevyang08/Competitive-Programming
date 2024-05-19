import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        long a;
        long[]  arr = new long[n - 1], temp = new long[n - 1];
        
        for (int i = 1; i < n; i++) {
            System.out.println("? " + 1 + " " + (i + 1));
            System.out.flush();
            arr[i - 1] = temp[i - 1] = scanner.nextLong();
        }

        Arrays.sort(temp);
        a = temp[1] - temp[0];
        if (a > n || a != temp[n - 2] - temp[n - 3]) a /= 2;

        for (int i = 0; i < n - 1; i++) {
            arr[i] /= a;
        }
        
        System.out.print("! " + a);
        for (long i : arr) System.out.print(" " + i);
        System.out.println();
    }
}
