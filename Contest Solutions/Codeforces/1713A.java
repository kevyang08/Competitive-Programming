import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt();
        	int minx = 0, miny = 0, maxx = 0, maxy = 0;
        	for (int i = 0; i < n; i++) {
        		int x = scanner.nextInt(), y = scanner.nextInt();
        		minx = Math.min(x, minx);
        		miny = Math.min(y, miny);
        		maxx = Math.max(x, maxx);
        		maxy = Math.max(y, maxy);
        	}
        	System.out.println(2 * Math.abs(minx) + 2 * Math.abs(miny) + 2 * maxx + 2 * maxy);
        }
    }
}
