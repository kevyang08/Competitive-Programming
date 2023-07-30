import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), dist[] = new int[n + 1];
        ArrayList<Pair>[] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<Pair>();
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>(n, (a, b) -> b.dist - a.dist);
        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
            adj[a].add(new Pair(b, c));
            adj[b].add(new Pair(a, c));
        }
        pq.offer(new Pair(1, Integer.MAX_VALUE));
        while (!pq.isEmpty()) {
            int c = pq.peek().to, d = pq.poll().dist;
            for (Pair p : adj[c]) {
                if (Math.min(d, p.dist) > dist[p.to]) {
                    dist[p.to] = Math.min(d, p.dist);
                    pq.offer(new Pair(p.to, Math.min(d, p.dist)));
                }
            }
        }
        System.out.println(0);
        for (int i = 2; i <= n; i++) System.out.println(dist[i]);
    }
}

class Pair {
    int to, dist;
    public Pair(int a, int b) {
        to = a;
        dist = b;
    }
}
