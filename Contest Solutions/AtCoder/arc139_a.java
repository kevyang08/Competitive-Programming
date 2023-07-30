import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int n = scanner.nextInt();
        long arr[] = new long[n + 1];
        for (int i = 1; i <= n; i++) {
        	int t = scanner.nextInt();
        	arr[i] = ((arr[i - 1] - arr[i])/((long)Math.pow(2, t)) + 1) * ((long)Math.pow(2, t));
        	while (Long.numberOfTrailingZeros(arr[i]) != t) arr[i] += (long)Math.pow(2, t);
//        	while (arr[i] <= arr[i - 1] || Long.numberOfTrailingZeros(arr[i]) != t) arr[i] += (long)Math.pow(2, t);
        }
        System.out.println(arr[n]);
    }
}
