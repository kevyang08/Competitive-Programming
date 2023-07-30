import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), h = scanner.nextInt(), m = scanner.nextInt(), hh = Integer.MAX_VALUE, mm = Integer.MAX_VALUE;
        	for (int i = 0; i < n; i++) {
        		int a = scanner.nextInt(), b = scanner.nextInt();
        		if (a < h || a == h && b < m) a += 24;
        		if (a < hh || a == hh && b < mm) {
        			hh = a;
        			mm = b;
        		}
        	}
        	if (mm < m) {
        		hh--;
        		mm += 60;
        	}
        	System.out.printf("%d %d\n", hh - h, mm - m);
        }
    }
}
