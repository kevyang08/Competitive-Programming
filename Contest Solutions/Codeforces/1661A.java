import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt();
        	int[] a = new int[n], b = new int[n];
        	long s = 0;
        	for (int i = 0; i < n; i++) a[i] = scanner.nextInt();
        	for (int i = 0; i < n; i++) b[i] = scanner.nextInt();
        	for (int i = 0; i < n - 1; i++) s += Math.min(Math.abs(a[i + 1] - a[i]) + Math.abs(b[i + 1] - b[i]), Math.abs(a[i + 1] - b[i]) + Math.abs(b[i + 1] - a[i]));
        	System.out.println(s);
        }
    }
}
