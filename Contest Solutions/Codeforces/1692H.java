import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt();
        while (t-- > 0) {
        	int n = scanner.nextInt(), m = 0, a = -1, l = -1, r = -1;
        	HashMap<Integer, Data> map = new HashMap<Integer, Data>();
        	for (int i = 0; i < n; i++) {
        		int x = scanner.nextInt();
        		if (!map.containsKey(x) || i - map.get(x).e >= map.get(x).l) map.put(x, new Data(i, i, 1));
        		map.get(x).l -= i - map.get(x).e - 1;
        		map.get(x).e = i;
        		map.get(x).l++;
        		if (map.get(x).l > m) {
        			a = x;
        			l = map.get(x).s + 1;
        			r = map.get(x).e + 1;
        			m = map.get(x).l;
        		}
        	}
        	System.out.printf("%d %d %d\n", a, l, r);
        }
    }
}
 
class Data {
	int s, e, l;
	public Data(int s, int e, int l) {
		this.s = s;
		this.e = e;
		this.l = l;
	}
}
