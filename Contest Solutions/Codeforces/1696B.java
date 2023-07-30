import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), c = 0;
        	boolean thing = false;
        	for (int i = 0; i < n; i++) {
        		int a = scanner.nextInt();
        		if (a > 0 && !thing) {
        			c++;
        			thing = true;
        		}
        		else if (a == 0) thing = false;
        	}
        	System.out.println(Math.min(c, 2));
        }
    }
}
