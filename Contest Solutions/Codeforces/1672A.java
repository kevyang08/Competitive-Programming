import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), turn = 0, cnt[] = new int[51];
        	for (int i = 0; i < n; i++) cnt[scanner.nextInt()]++;
        	while (true) {
        		int i = 2;
        		for (; i < 51; i++) {
        			if (cnt[i] > 0) {
        				cnt[i/2]++;
        				cnt[i/2 + i%2]++;
        				cnt[i]--;
        				turn++;
        				break;
        			}
        		}
        		if (i == 51) break;
        	}
        	System.out.println(turn%2 == 1 ? "errorgorn" : "maomao90");
        }
    }
}
