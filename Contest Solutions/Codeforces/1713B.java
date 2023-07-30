import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), a[] = new int[n];
        	boolean up = true, down = false, ans = true;
        	for (int i = 0; i < n; i++) a[i] = scanner.nextInt();
        	for (int i = 1; i < n; i++) {
        		if (a[i] < a[i - 1] && up) {
    				up = false;
    				down = true;
        		}
        		else if (a[i] > a[i - 1] && down) ans = false;
        	}
        	System.out.println(ans ? "YES" : "NO");
        }
    }
}
