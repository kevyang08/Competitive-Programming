import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int t = scanner.nextInt();
		for (int x = 1; x <= t; x++) {
			int c = Integer.MAX_VALUE, m = Integer.MAX_VALUE, y = Integer.MAX_VALUE, k = Integer.MAX_VALUE;
			for (int i = 0; i < 3; i++) {
				c = Math.min(c, scanner.nextInt());
				m = Math.min(m, scanner.nextInt());
				y = Math.min(y, scanner.nextInt());
				k = Math.min(k, scanner.nextInt());
			}
			if (c + m + y + k > 1000000) k = Math.max(0, k + 1000000 - (c + m + y + k));
			if (c + m + y + k > 1000000) m = Math.max(0, m + 1000000 - (c + m + y + k));
			if (c + m + y + k > 1000000) y = Math.max(0, y + 1000000 - (c + m + y + k));
			System.out.printf("Case #%d: ", x);
			if (c + m + y + k != 1000000) System.out.println("IMPOSSIBLE");
			else System.out.printf("%d %d %d %d\n", c, m, y, k);
		}
	}
}
