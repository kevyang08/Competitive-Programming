import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        int t = scanner.nextInt();
        while (t-- > 0) {
        	HashMap<Integer, ArrayList<Integer>> arr = new HashMap<Integer, ArrayList<Integer>>();
        	int n = scanner.nextInt(), k = scanner.nextInt();
        	for (int i = 0; i < n; i++) {
        		int u = scanner.nextInt();
        		if (!arr.containsKey(u)) arr.put(u, new ArrayList<Integer>());
        		arr.get(u).add(i);
        	}
        	for (int i : arr.keySet()) Collections.sort(arr.get(i));
        	for (int i = 0; i < k; i++) {
        		int a = scanner.nextInt(), b = scanner.nextInt();
        		System.out.println(arr.containsKey(a) && arr.containsKey(b) && arr.get(a).get(0) < arr.get(b).get(arr.get(b).size() - 1) ? "YES" : "NO");
        	}
        }
    }
}
