import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt();
        	Integer a[] = new Integer[n];
        	boolean thing = true;
        	for (int i = 0; i < n; i++) a[i] = scanner.nextInt();
        	Arrays.sort(a);
    		a[n - 1] += a[n - 1]%10;
        	if (a[n - 1]%10 == 0) {
        		for (int i = 0; i < n - 1; i++) {
        			if (a[i] + a[i]%10 != a[n - 1]) thing = false;
        		}
        	}
        	else {
        		for (int i = 0; i < n - 1; i++) {
//        			if (a[i]%2 == 1) a[i] += a[i]%10;
        			boolean temp = false;
        			for (int j = 0; j < 5; j++) {
        				if ((a[n - 1] - a[i])%20 == 0) temp = true;
        				a[i] += a[i]%10;
        			}
        			thing &= temp;
        		}
        	}
    		System.out.println(thing ? "YES" : "NO");
        }
    }
}
