import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), r = scanner.nextInt(), b = scanner.nextInt(), cr = 0, cb = 0;
        	double max = Math.ceil((double)r/(b + 1));
        	for (int i = 0, j = 0; i < n; i++) {
        		if (j >= max && b > 0) {
        			System.out.print('B');
        			j = 0;
        			b--;
        			max = Math.ceil((double)r/(b + 1));
        		}
        		else {
        			System.out.print('R');
        			j++;
        			r--;
        		}
//    			System.out.print('R');
//    			cr++;
//    			r--;
//    			if (cr > (double)r/(b + 1) && b > 0 && i < n - 1) {
//        			System.out.print('B');
//        			cb++;
//        			b--;
//        			cr = 0;
//        			i++;
//        		}
        	}
        	System.out.println();
        }
    }
}
