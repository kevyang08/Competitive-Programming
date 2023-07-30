import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        for (int k = 0; k < 5; k++) {
        	int a = scanner.nextInt(), b = scanner.nextInt(), x = scanner.nextInt(), y = scanner.nextInt(), dx = x - a, dy = y - b, temp = gcd(Math.abs(dx), Math.abs(dy)), c = 0;
        	dx /= temp;
        	dy /= temp;
        	while ((dx < 0 ? a >= x : a <= x) && (dy < 0 ? b >= y : b <= y)) {
        		c++;
        		a += dx;
        		b += dy;
        	}
        	System.out.println(c - 2);
        }
    }
    
    public static int gcd(int a, int b) {
    	return a%b == 0 ? b : gcd(b, a%b);
    }
}
