import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int n = scanner.nextInt(), arr[][] = new int[n + 2][n + 2];
        arr[0][0] = 1;
        for (int i = 1; i <= n; i++) {
        	for (int j = 1; j <= i; j++) {
        		arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        		System.out.print(j == 1 ? arr[i][j] : " " + arr[i][j]);
        	}
        	System.out.println();
        }
    }
}
