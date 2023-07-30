import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), l = scanner.nextInt(), r = scanner.nextInt();
        	boolean thing = true;
        	for (int i = 1; i <= n; i++) {
        		if (r/i * i >= l && r/i * i <= r) continue;
        		thing = false;
        	}
        	System.out.println(thing ? "YES" : "NO");
        	if (thing) {
        		for (int i = 1; i <= n; i++) {
            		System.out.print(i == 1 ? r/i * i : " " + r/i * i);
            	}
        		System.out.println();
        	}
        }
    }
}
