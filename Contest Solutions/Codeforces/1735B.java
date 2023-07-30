import java.io.*;
import java.util.*;
 
public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int t = scanner.nextInt();
		while (t-- > 0) {
			int n = scanner.nextInt(), a[] = new int[n], mn = Integer.MAX_VALUE;
			long c = 0;
			for (int i = 0; i < n; i++) {
				a[i] = scanner.nextInt();
				mn = Math.min(a[i], mn);
			}
			for (int i = 0; i < n; i++) if (a[i] >= 2 * mn) c += a[i]/(2 * mn - 1) + (a[i]%(2 * mn - 1) == 0 ? 0 : 1) - 1;
			System.out.println(c);
		}
	}
}
