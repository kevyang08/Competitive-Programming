import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	HashMap<Integer, Integer> val = new HashMap<Integer, Integer>();
        	int n = scanner.nextInt(), m = scanner.nextInt(), cnt[] = new int[n + 1], a = Integer.MAX_VALUE, b = Integer.MAX_VALUE;
        	Integer[] arr = new Integer[n];
        	ArrayList<Integer>[] adj = new ArrayList[n + 1];
        	for (int i = 1; i <= n; i++) {
        		arr[i - 1] = i;
        		val.put(i, scanner.nextInt());
        		adj[i] = new ArrayList<Integer>();
        	}
        	Arrays.sort(arr, (i, j) -> val.get(i) - val.get(j));
        	for (int i = 0; i < m; i++) {
        		int x = scanner.nextInt(), y = scanner.nextInt();
        		cnt[x]++;
        		cnt[y]++;
        		adj[x].add(y);
        		adj[y].add(x);
        	}
        	if (m%2 != 0) {
        		for (int i = 0; i < n; i++) {
        			if (cnt[arr[i]]%2 != 0) {
        				a = val.get(arr[i]);
        				break;
        			}
        		}
        		
        		for (int i = 0; i < n; i++) {
        			if (cnt[arr[i]]%2 == 0) {
        				int min = Integer.MAX_VALUE, idx = -1, temp = 0;
                		for (int j : adj[arr[i]]) {
                			if (cnt[j]%2 == 0 && val.get(j) < min) {
                				idx = j;
                				min = val.get(j);
                			}
                		}
                		if (idx != -1) {
	                		temp += val.get(arr[i]) + val.get(idx);
	                		b = Math.min(b, temp);
                		}
        			}
        		}
        	}
        	System.out.println(m%2 == 0 ? 0 : Math.min(a, b));
        }
    }
}
