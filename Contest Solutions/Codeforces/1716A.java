import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt();
        	if (n < 4) System.out.println(n > 1 ? 1 : 2);
        	else System.out.println(n%3 == 0 ? n/3 : n/3 + 1);
        }
    }
}
