import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
//        Scanner scanner = new Scanner(System.in);
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	int t = Integer.parseInt(br.readLine()), dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};
    	while (t-- > 0) {
    		StringTokenizer st = new StringTokenizer(br.readLine());
    		int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken()), r = Integer.parseInt(st.nextToken()) - 1, c = Integer.parseInt(st.nextToken()) - 1;
    		char[][] arr = new char[n][n];
    		boolean[][] vis = new boolean[n][n];
    		Queue<Integer> qr = new LinkedList<Integer>(), qc = new LinkedList<Integer>();
    		qr.add(r);
    		qc.add(c);
    		while (!qr.isEmpty()) {
    			r = qr.poll();
    			c = qc.poll();
    			if (vis[r][c]) continue;
    			arr[r][c] = 'X';
    			vis[r][c] = true;
    			if (!vis[(r + 1)%n][(c + 1)%n]) {
    				qr.add((r + 1)%n);
    				qc.add((c + 1)%n);
    			}
    			if (r - 1 > -1 && c - 1 > -1 && !vis[(r - 1)%n][(c - 1)%n]) {
    				qr.add((r - 1)%n);
    				qc.add((c - 1)%n);
    			}
    			for (int i = 0; i < 4; i++) {
    				if (r + k * dr[i] > -1 && c + k * dc[i] > -1 && !vis[(r + k * dr[i])%n][(c + k * dc[i])%n]) {
    					qr.add((r + k * dr[i])%n);
    					qc.add((c + k * dc[i])%n);
    				}
    			}
    		}
    		for (int i = 0; i < n; i++) {
    			for (int j = 0; j < n; j++) System.out.print(arr[i][j] == 'X' ? 'X' : '.');
    			System.out.println();
    		}
    	}
    }
}
