import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt();
        	long res = 1;
        	for (int i = 1; i <= n/2; i++) {
        		res *= i * i;
        		res %= 998244353;
        	}
        	System.out.println(n%2 == 0 ? res : 0);
        }
    }
}
