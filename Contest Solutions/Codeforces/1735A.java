import java.io.*;
import java.util.*;
 
public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int t = scanner.nextInt();
		while (t-- > 0) {
			int n = scanner.nextInt();
			System.out.println(n/3 - 2);
		}
	}
}
