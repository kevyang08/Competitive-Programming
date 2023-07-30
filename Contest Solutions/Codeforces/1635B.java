import java.io.*;
import java.util.*;
 
public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int t = scanner.nextInt();
		while (t-- > 0) {
			int n = scanner.nextInt(), c = 0;
			int[] arr = new int[n];
			
			for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
			
			boolean flag = false;
			for (int i = 1; i < n - 1; i++) {
				if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) flag = true;
				else if (flag) {
					arr[i] = Math.max(arr[i - 1], arr[i + 1]);
					flag = false;
					c++;
				}
			}
			if (flag) {
				arr[n - 2] = Math.max(arr[n - 1], arr[n - 3]);
				c++;
			}
			
			System.out.println(c);
			for (int i = 0; i < n; i++) System.out.print(i == 0 ? arr[i] : " " + arr[i]);
			System.out.println();
		}
	}
}
