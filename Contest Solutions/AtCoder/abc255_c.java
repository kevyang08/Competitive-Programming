import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        
        long x = scanner.nextLong(), a = scanner.nextLong(), d = scanner.nextLong(), n = scanner.nextLong();
        if (d >= 0) {
	        if (x <= a) System.out.println(a - x);
	        else if (x >= a + d * (n - 1)) System.out.println(x - (a + d * (n - 1)));
	        else {
	        	long temp = (x - a)/d * d + a;
	        	if (temp + d - x < x - temp) System.out.println(temp + d - x);
	        	else System.out.println(x - temp);
	        }
        }
        else {
        	if (x >= a) System.out.println(x - a);
	        else if (x <= a + d * (n - 1)) System.out.println(a + d * (n - 1) - x);
	        else {
	        	long temp = (x - a)/d * d + a;
	        	if (x - (temp + d) < temp - x) System.out.println(x - (temp + d));
	        	else System.out.println(temp - x);
	        }
        }
    }
}
