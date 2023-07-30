import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        int n = scanner.nextInt(), k = scanner.nextInt(), q = scanner.nextInt(), a[] = new int[k + 1];
        boolean[] arr = new boolean[n + 1];
        for (int i = 1; i <= k; i++) {
        	a[i] = scanner.nextInt();
        	arr[a[i]] = true;
        }
        while (q-- > 0) {
        	int l = scanner.nextInt();
        	if (a[l] < n && !arr[a[l] + 1]) {
        		arr[a[l]] = false;
        		a[l]++;
        		arr[a[l]] = true;
        	}
        }
        for (int i = 1; i <= k; i++) System.out.print(i == 1 ? a[i] : " " + a[i]);
        System.out.println();
    }
}
