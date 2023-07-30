import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
 
        int q = scanner.nextInt(), cnt = 0, arr[] = new int[200001], tree[] = new int[200001];
        Query[] qrr = new Query[q];
        HashMap<Integer, Integer> ref = new HashMap<Integer, Integer>(), dref = new HashMap<Integer, Integer>();
        Arrays.fill(arr, -1);
        for (int i = 0; i < q; i++) {
        	int op = scanner.nextInt(), x = 0, c = 0;
        	if (op == 1 || op == 2) x = scanner.nextInt();
        	if (op == 2) c = scanner.nextInt();
        	qrr[i] = new Query(op, x, c);
        	if (op == 1) arr[i] = x;
        }
        Arrays.sort(arr);
        for (int i = 0; i < 200001; i++) {
        	while (i < 200000 && arr[i] == arr[i + 1]) i++;
        	ref.put(arr[i], cnt);
        	dref.put(cnt, arr[i]);
        	cnt++;
        }
        for (int i = 0; i < q; i++) {
        	if (qrr[i].op == 1) {
        		int x = ref.get(qrr[i].x);
        		for (int j = x; j < 200001; j += j & -j) tree[j]++;
        	}
        	else if (qrr[i].op == 2) {
        		int x = ref.containsKey(qrr[i].x) ? ref.get(qrr[i].x) : 200000, c = query(x, tree) - query(x - 1, tree);
        		for (int j = x; j < 200001; j += j & -j) tree[j] -= Math.min(c, qrr[i].c);
        	}
        	else {
        		int min = 0, max = 0;
        		int l = 1, r = 200000, c = 0;
        		while (l < r) {
                    int m = (l + r)/2;
                    c = query(m, tree);
                    if (c > 0) r = m;
                    else l = m + 1;
                }
        		min = dref.get(l);
        		l = 1;
        		r = 200000;
        		while (l < r) {
                    int m = (l + r)/2;
                    c = query(r, tree) - query(m, tree);
                    if (c > 0) l = m + 1;
                    else r = m;
                }
        		max = dref.get(l);
        		System.out.println(max - min);
        	}
        }
    }
    public static int query(int x, int[] tree) {
    	int cnt = 0;
    	for (int i = x; i > 0; i -= i & -i) {
    		cnt += tree[i];
    	}
    	return cnt;
    }
}
 
class Query {
	int op, x, c;
	public Query(int op, int x, int c) {
		this.op = op;
		this.x = x;
		this.c = c;
	}
}
