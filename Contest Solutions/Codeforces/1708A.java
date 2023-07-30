import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), a[] = new int[n];
        	boolean thing = true;
        	for (int i = 0; i < n; i++) {
        		a[i] = scanner.nextInt();
        		if (a[i]%a[0] != 0) thing = false;
        	}
        	System.out.println(thing ? "YES" : "NO");
        }
    }
}
