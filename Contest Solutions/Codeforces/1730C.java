import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        while (t-- > 0) {
        	char[] s = scanner.next().toCharArray();
        	boolean[] used = new boolean[s.length];
        	PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        	int mn = s[s.length - 1] - '0';
        	for (int i = s.length - 1; i >= 0; i--) {
        		if (s[i] - '0' > mn) {
        			pq.offer(Math.min(s[i] - '0' + 1, 9));
        			used[i] = true;
        		}
        		else mn = s[i] - '0';
        	}
//        	if (!pq.isEmpty()) {
//	        	for (int i = s.length - 1; i >= 0; i--) {
//	        		if (!used[i] && s[i] - '0' > pq.peek()) {
//	        			pq.offer(Math.min(s[i] - '0' + 1, 9));
//	        			used[i] = true;
//	        		}
//	        	}
//        	}
        	for (int i = 0; i < s.length; i++) if (!used[i]) {
        		while (!pq.isEmpty() && pq.peek() < s[i] - '0') System.out.print(pq.poll());
        		System.out.print(s[i]);
        	}
        	while (!pq.isEmpty()) System.out.print(pq.poll());
        	System.out.println();
        }
    }
}
