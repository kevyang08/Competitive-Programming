import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
//        Scanner scanner = new Scanner(System.in);
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	int t = Integer.parseInt(br.readLine());
    	while (t-- > 0) {
    		int n = Integer.parseInt(br.readLine()), a[] = new int[n], b[] = new int[n];
    		boolean thing = true;
    		StringTokenizer st = new StringTokenizer(br.readLine());
    		for (int i = 0; i < n; i++) a[i] = Integer.parseInt(st.nextToken());
    		st = new StringTokenizer(br.readLine());
    		for (int i = 0; i < n; i++) b[i] = Integer.parseInt(st.nextToken());
    		for (int i = 0; i < n; i++) {
    			if (a[i] > b[i] || a[i] < b[i] && b[i] - 1 > b[(i + 1)%n]) thing = false;
    		}
    		System.out.println(thing ? "YES" : "NO");
    	}
    }
}
