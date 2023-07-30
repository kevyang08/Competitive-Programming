import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	String s = scanner.next();
        	int a = 0;
        	for (int i = 0; i < s.length(); i++) {
        		if (s.charAt(i) == 'A') a++;
        		else {
        			if (a == 0) {
        				a++;
        				break;
        			}
        			else {
        				a--;
        				if (i == s.length() - 1) a = 0;
        			}
        		}
        	}
        	System.out.println(a == 0 ? "YES" : "NO");
        }
    }
}
