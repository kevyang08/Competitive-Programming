import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int h = scanner.nextInt(), w = scanner.nextInt(), r1 = -1, c1 = -1, r2 = -1, c2 = -1;
        for (int i = 0; i < h; i++) {
        	String s = scanner.next();
        	for (int j = 0; j < w; j++) {
        		if (s.charAt(j) == 'o') {
        			if (r1 == -1) {
        				r1 = i;
        				c1 = j;
        			}
        			else {
        				r2 = i;
        				c2 = j;
        			}
        		}
        	}
        }
        System.out.println(Math.abs(r2 - r1) + Math.abs(c2 - c1));
    }
}
