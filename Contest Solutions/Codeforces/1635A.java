import java.io.*;
import java.util.*;
 
public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int t = scanner.nextInt();
		while (t-- > 0) {
			int n = scanner.nextInt();
			long sum = 0;
			int[] arr = new int[n];
			
			for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
//			Arrays.sort(arr);
			
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					arr[j] = Math.min(arr[j], arr[j] ^ (arr[j] & arr[i]));
				}
			}
			
			for (int i = 0; i < n; i++) sum += arr[i];
			System.out.println(sum);
//			System.out.println(Arrays.toString(arr));
		}
	}
}
