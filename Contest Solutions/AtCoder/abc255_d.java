import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), q = scanner.nextInt();
        long arr[] = new long[n + 1], temp[] = new long[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = scanner.nextLong();
        Arrays.sort(arr);
        System.arraycopy(arr, 0, temp, 0, n + 1);
        for (int i = 1; i <= n; i++) arr[i] += arr[i - 1];
        while (q-- > 0) {
        	long x = scanner.nextLong();
        	int l = 0, r = n;
        	while (l < r) {
        		int m = (l + r)/2;
        		if (temp[m] >= x) r = m - 1;
        		else l = m + 1;
        	}
        	if (temp[l] > x) l--;
        	System.out.println(x * l - arr[l] + arr[n] - arr[l] - x * (n - l));
        }
    }
}
