import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int t = scanner.nextInt(), cnt[] = new int[500001];
        while (t-- > 0) {
        	int n = scanner.nextInt();
        	ArrayList<Integer> a = new ArrayList<Integer>();
        	for (int i = 0; i < n; i++) {
        		int x = scanner.nextInt();
        		if (cnt[x] == 0 && x != 0) a.add(x);
        		cnt[x]++;
        	}
//        	System.out.println(a);
//        	System.out.println(cnt[0]);
        	while (a.size() > 1) {
        		ArrayList<Integer> temp = new ArrayList<Integer>();
        		int z = cnt[0];
        		for (int i = 0; i < a.size(); i++) {
        			cnt[0] += cnt[a.get(i)] - 1;
        			cnt[a.get(i)] = 0;
        			if (i == 0 && z > 0) {
        				if (cnt[a.get(i)] == 0) temp.add(a.get(i));
        				cnt[a.get(i)]++;
        			}
        			else if (i > 0) {
        				if (cnt[a.get(i) - a.get(i - 1)] == 0) temp.add(a.get(i) - a.get(i - 1));
        				cnt[a.get(i) - a.get(i - 1)]++;
        			}
        		}
        		a = new ArrayList<Integer>();
        		for (int i = 0; i < temp.size(); i++) a.add(temp.get(i));
        		Collections.sort(a);
        		if (z > 0) cnt[0]--;
//        		System.out.println(a);
        	}
        	if (!a.isEmpty() && cnt[a.get(0)] > 1 && cnt[0] == 0) {
        		cnt[a.get(0)] = 0;
        		a.clear();
        	}
        	System.out.println(!a.isEmpty() ? a.get(0) : 0);
        	cnt[0] = 0;
        	if (!a.isEmpty()) cnt[a.get(0)] = 0; 
        }
    }
}
