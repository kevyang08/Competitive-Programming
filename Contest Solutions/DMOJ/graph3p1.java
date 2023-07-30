import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(), m = scanner.nextInt(), mx = 0;
        ArrayList<Integer>[] adj = new ArrayList[n + 1];
        boolean[] vis = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<Integer>(), qt = new LinkedList<Integer>();
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<Integer>();
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt(), b = scanner.nextInt();
            adj[a].add(b);
            adj[b].add(a);
        }
        int k = scanner.nextInt();
        for (int i = 0; i < k; i++) {
            q.add(scanner.nextInt());
            qt.add(0);
        }
        while (!q.isEmpty()) {
            int cur = q.poll(), ct = qt.poll();
            if (vis[cur]) continue;
            vis[cur] = true;
            mx = Math.max(mx, ct);
            for (int i : adj[cur]) {
                if (!vis[i]) {
                    q.add(i);
                    qt.add(ct + 1);
                }
            }
        }
        System.out.println(mx);
    }
}
