import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int t = scanner.nextInt();
		while (t-- > 0) {
			int n = scanner.nextInt(), prev = 0;
			boolean up = false, down = false, thing = true;
			for (int i = 0; i < n; i++) {
				int a = scanner.nextInt();
				if (a != 0 && prev != 0) {
					if (a == prev || a > prev && up || a < prev && down) thing = false;
					if (a > prev) {
						up = true;
						down = false;
					}
					else {
						down = true;
						up = false;
					}
				}
				else {
					if (up) {
						up = false;
						down = true;
					}
					else if (down) {
						down = false;
						up = true;
					}
				}
				prev = a;
			}
			System.out.println(thing ? "YES" : "NO");
		}
	}
}
