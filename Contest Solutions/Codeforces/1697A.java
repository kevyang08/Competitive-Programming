import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), m = scanner.nextInt(), s = 0;
        	for (int i = 0; i < n; i++) s += scanner.nextInt();
        	System.out.println(s > m ? s - m : 0);
        }
    }
}
