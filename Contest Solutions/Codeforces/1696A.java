import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt();
        	long z = scanner.nextLong(), m = 0;
        	for (int i = 0; i < n; i++) {
        		long a = scanner.nextLong();
        		m = Math.max(m, z|a);
        	}
        	System.out.println(m);
        }
    }
}
