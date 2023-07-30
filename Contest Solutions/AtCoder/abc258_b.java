import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
    	
        int n = Integer.parseInt(st.nextToken()), q = Integer.parseInt(st.nextToken()), idx = 0;
        String s = br.readLine();
        while (q-- > 0) {
        	st = new StringTokenizer(br.readLine());
        	int op = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken());
        	if (op == 1) idx = (idx - x + n)%n;
        	else System.out.println(s.charAt((idx + x - 1)%n));
        }
    }
}
