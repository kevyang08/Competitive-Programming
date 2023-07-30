import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
    	
        int n = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken()), arr[] = new int[n];
        HashMap<Integer, Integer> cnt = new HashMap<Integer, Integer>();
        Deque<Integer> dq = new LinkedList<Integer>();
        long min = Long.MAX_VALUE, curr = 0;
        for (int i = 0; i < n; i++) {
        	st = new StringTokenizer(br.readLine());
        	int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
        	if (i == 0) {
        		curr = a + (long)b * x;
        		min = curr;
        		dq.add(b);
        		cnt.put(b, x - 1);
        		continue;
        	}
        	if (!dq.isEmpty()) {
        		curr -= dq.peekLast();
        		cnt.put(dq.peekLast(), cnt.get(dq.peekLast()) - 1);
        		if (cnt.get(dq.peekLast()) == 0) dq.pollLast();
        	}
        	curr += a + b;
        	int c = 0;
        	while (!dq.isEmpty() && dq.peekLast() >= b) {
        		int temp = dq.pollLast();
        		c += cnt.get(temp);
        		curr -= cnt.get(temp) * (long)temp;
        		cnt.put(temp, 0);
        	}
        	curr += c * (long)b;
        	dq.add(b);
        	cnt.put(b, c);
        	min = Math.min(curr, min);
        }
        System.out.println(min);
    }
}
