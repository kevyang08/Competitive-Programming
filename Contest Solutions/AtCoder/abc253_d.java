import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        long n = scanner.nextLong(), a = scanner.nextLong(), a1 = n/a, b = scanner.nextLong(), b1 = n/b, c = lcm(a, b), c1 = n/c;
        System.out.println(n * (n + 1)/2 - a * a1 * (a1 + 1)/2 - b * b1 * (b1 + 1)/2 + c * c1 * (c1 + 1)/2);
    }
    public static long gcd(long a, long b) {
        return a%b == 0 ? b : gcd(b, a%b);
    }
    public static long lcm(long a, long b) {
    	return a * b/gcd(a, b); 
  	}
}
