import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int t = scanner.nextInt();
		for (int x = 1; x <= t; x++) {
			int r = scanner.nextInt(), c = scanner.nextInt();
			System.out.printf("Case #%d:\n", x);
			for (int i = 0; i < 2; i++) {
				System.out.print("..");
				for (int j = 1; j < c; j++) {
					System.out.print(i%2 == 0 ? "+-" : "|.");
				}
				System.out.println(i%2 == 0 ? "+" : "|");
			}
			for (int i = 2; i < 2 * r; i++) {
				for (int j = 0; j < c; j++) {
					System.out.print(i%2 == 0 ? "+-" : "|.");
				}
				System.out.println(i%2 == 0 ? "+" : "|");
			}
			for (int j = 0; j < c; j++) {
				System.out.print("+-");
			}
			System.out.println("+");
		}
	}
}
