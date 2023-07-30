import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
        int t = scanner.nextInt();
        while (t-- > 0) {
        	String w = scanner.next();
        	int p = scanner.nextInt(), c = 0, j = 0;
        	boolean[] arr = new boolean[w.length()];
        	ArrayList<Integer> idx = new ArrayList<Integer>();
        	for (int i = 0; i < w.length(); i++) {
        		idx.add(i);
        		c += w.charAt(i) - 'a' + 1;
        	}
        	Collections.sort(idx, (a, b) -> w.charAt(b) - w.charAt(a));
        	while (c > p) {
        		arr[idx.get(j)] = true;
        		c -= w.charAt(idx.get(j++)) - 'a' + 1;
        	}
        	for (int i = 0; i < w.length(); i++) {
        		if (!arr[i]) System.out.print(w.charAt(i));
        	}
        	System.out.println();
        }
    }
}
