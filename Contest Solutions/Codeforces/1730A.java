import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), c = scanner.nextInt(), cnt[] = new int[101], ans = 0;
        	for (int i = 0; i < n; i++) cnt[scanner.nextInt()]++;
        	for (int i = 0; i <= 100; i++) ans += Math.min(c, cnt[i]);
        	System.out.println(ans);
        }
    }
}
