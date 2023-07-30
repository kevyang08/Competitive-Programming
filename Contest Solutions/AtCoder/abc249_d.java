import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int n = scanner.nextInt(), cnt[] = new int[200001];
        long c = 0;
        for (int i = 0; i < n; i++) cnt[scanner.nextInt()]++;
        for (int i = 1; i < 200001; i++) {
        	int l = 1, r = i;
        	while (r < 200001) {
        		c += (long)cnt[l] * cnt[r] * cnt[i];
        		l++;
        		r += i;
        	}
        }
        System.out.println(c);
    }
}
