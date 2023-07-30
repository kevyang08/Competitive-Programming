import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
    	
    	int n = scanner.nextInt(), k = scanner.nextInt(), min = Integer.MAX_VALUE;
    	ArrayList<Integer> list = new ArrayList<Integer>(), idlist = new ArrayList<Integer>();
    	for (int i = 0; i < n; i++) {
    		int x = scanner.nextInt();
    		if (i < k) {
    			while (!list.isEmpty() && list.get(list.size() - 1) >= x) {
    				list.remove(list.size() - 1);
    				idlist.remove(list.size());
    			}
    			list.add(x);
    			idlist.add(i);
    		}
    		else {
    			int l = 0, r = list.size() - 1;
    			while (l <= r) {
    				int m = (l + r)/2;
    				if (list.get(m) < x) l = m + 1;
    				else r = m - 1;
    			}
    			if (r != -1 && i - idlist.get(r) < min) min = i - idlist.get(r);
    		}
    	}
    	System.out.println(min != Integer.MAX_VALUE ? min : -1);
    }
}
