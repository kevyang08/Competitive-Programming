import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int m = scanner.nextInt(), thing = (int)Math.pow(10, String.valueOf(m).length() - 1);
        	System.out.println(m - thing);
        }
    }
}
