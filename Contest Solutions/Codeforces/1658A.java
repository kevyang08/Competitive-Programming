import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), c = 0;
        	String s = scanner.next();
        	for (int i = 1; i < n; i++) {
        		if (s.charAt(i - 1) == '0' && s.charAt(i) == '0') c += 2;
        	}
        	for (int i = 2; i < n; i++) {
        		if (s.charAt(i - 2) == '0' && s.charAt(i - 1) == '1' && s.charAt(i) == '0') c++;
        	}
        	System.out.println(c);
        }
    }
}
