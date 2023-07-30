import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int[] arr = new int[10000001];
        for (int i = 1; i <= 10000000; i++) 
        for (int j = i + i; j <= 10000000; j += i) 
        arr[j] += i;
        int a = scanner.nextInt(), b = scanner.nextInt();
        long c = 0;
        for (int i = a; i <= b; i++) c += Math.abs(i - arr[i]);
        System.out.println(c);
    }
}
