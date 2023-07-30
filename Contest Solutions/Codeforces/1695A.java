import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), m = scanner.nextInt(), arr[][] = new int[n][m], mx = -1, my = -1, max = Integer.MIN_VALUE;
        	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        		arr[i][j] = scanner.nextInt();
        		if (arr[i][j] > max) {
        			mx = i;
        			my = j;
        			max = arr[i][j];
        		}
        	}
        	System.out.println(Math.max(mx + 1, n - mx) * Math.max(my + 1, m - my));
        }
    }
}
