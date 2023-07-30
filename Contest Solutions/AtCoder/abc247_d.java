import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int n = scanner.nextInt();
        Queue<Pair> q = new LinkedList<Pair>();
        for (int i = 0; i < n; i++) {
        	int op = scanner.nextInt();
        	if (op == 1) q.offer(new Pair(scanner.nextInt(), scanner.nextInt()));
        	else {
        		int c = scanner.nextInt();
        		long s = 0;
        		while (!q.isEmpty() && c > 0) {
        			if (c >= q.peek().c) {
        				Pair cur = q.poll();
        				s += (long)cur.c * cur.x;
        				c -= cur.c;
        			}
        			else {
        				s += (long)(c) * q.peek().x;
        				q.peek().c -= c;
        				break;
        			}
        		}
        		System.out.println(s);
        	}
        }
    }
}
 
class Pair {
	int x, c;
	public Pair(int x, int c) {
		this.x = x;
		this.c = c;
	}
}
