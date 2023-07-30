import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), a[] = new int[n], cnt[] = new int[n + 1], c = 0;
        	HashSet<Integer> bruh = new HashSet<Integer>();
        	for (int i = 0; i < n; i++) {
        		a[i] = scanner.nextInt();
        		cnt[a[i]]++;
        		if (cnt[a[i]] > 1) bruh.add(a[i]);
        	}
        	for (int i = 0; i < n; i++) {
        		if (bruh.isEmpty()) break;
        		cnt[a[i]]--;
        		c++;
        		if (cnt[a[i]] < 2 && bruh.contains(a[i])) bruh.remove(a[i]);
        	}
        	System.out.println(c);
        }
    }
}
