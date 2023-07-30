import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        
        int r = scanner.nextInt(), c = scanner.nextInt();
        for (int i = 1; i <= 2; i++) {
        	for (int j = 1; j <= 2; j++) {
        		int a = scanner.nextInt();
        		if (i == r && j == c) System.out.println(a);
        	}
        }
    }
}
