import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
//    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	int t = scanner.nextInt();
    	while (t-- > 0) {
    		int n = scanner.nextInt();
    		System.out.println(2 * (n/3) + 2 * (n/2) + n);
    	}
    }
}
