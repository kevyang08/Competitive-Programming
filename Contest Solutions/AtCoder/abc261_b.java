import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int n = scanner.nextInt();
        char[][] a = new char[n][n];
        boolean valid = true;
        
        for (int i = 0; i < n; i++) {
        	a[i] = scanner.next().toCharArray();
        	for (int j = 0; j < i; j++) {
        		if (a[i][j] == 'D' && a[j][i] != 'D' || a[j][i] == 'D' && a[i][j] != 'D') valid = false;
        		if (a[i][j] == 'W' && a[j][i] != 'L' || a[j][i] == 'W' && a[i][j] != 'L') valid = false;
        		if (a[i][j] == 'L' && a[j][i] != 'W' || a[j][i] == 'L' && a[i][j] != 'W') valid = false;
        	}
        }
        
//        for (int i = 0; i < n; i++) {
//        	for (int j = 0; j < n; j++) {
//        		if (a[i][j] == 'D' && a[j][i] != 'D' || a[j][i] == 'D' && a[i][j] != 'D') valid = false;
//        		if (a[i][j] == 'W' && a[j][i] != 'L' || a[j][i] == 'W' && a[i][j] != 'L') valid = false;
//        	}
//        }
        
        System.out.println(valid ? "correct" : "incorrect");
    }
}
