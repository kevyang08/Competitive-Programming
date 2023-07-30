import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt();
        	if (n%2 == 0) {
        		for (int i = 1; i <= n; i++) {
	        		System.out.print(i == 1 ? "2" : i%2 == 0 ? " " + (i - 1) : " " + (i + 1));
            	}
        	}
        	else {
	        	for (int i = 1; i < n; i++) {
	        		System.out.print(i == 1 ? n : i%2 == 0 ? " " + (i - 1) : " " + (i + 1));
	        	}
	        	System.out.print(n == 1 ? "1" : " 2");
        	}
        	System.out.println();
        }
    }
}
