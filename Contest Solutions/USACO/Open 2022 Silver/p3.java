import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        String s = br.readLine();
        int q = Integer.parseInt(br.readLine()), n = s.length();
        int[] c = new int[n + 1], o = new int[n + 1], w = new int[n + 1];
        
        for (int i = 1; i <= n; i++) {
        	c[i] = c[i - 1];
        	o[i] = o[i - 1];
        	w[i] = w[i - 1];
        	if (s.charAt(i - 1) == 'C') c[i]++;
        	else if (s.charAt(i - 1) == 'O') o[i]++;
        	else w[i]++;
        }
        
        while (q-- > 0) {
        	st = new StringTokenizer(br.readLine());
        	int l = Integer.parseInt(st.nextToken()), r = Integer.parseInt(st.nextToken());
        	System.out.print((o[r] - o[l - 1])%2 == (w[r] - w[l - 1])%2 && (w[r] - w[l - 1])%2 != (c[r] - c[l - 1])%2 ? 'Y' : 'N');
        }
        System.out.println();
    }
}
