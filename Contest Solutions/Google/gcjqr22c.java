import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int t = scanner.nextInt();
		for (int x = 1; x <= t; x++) {
			int n = scanner.nextInt(), c = 0, thing = 1;
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
			Arrays.sort(arr);
			for (int i : arr) {
				if (i >= thing) {
					c++;
					thing++;
				}
			}
			System.out.printf("Case #%d: %d\n", x, c);
		}
	}
}
