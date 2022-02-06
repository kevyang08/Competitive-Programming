import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt(), m = scanner.nextInt(), c = 0;
    ArrayList<Edge>[] adj = new ArrayList[n + 1];

    for (int i = 1; i <= n; i++) adj[i] = new ArrayList<Edge>();

    for (int i = 0; i < m; i++) {
      int a = scanner.nextInt(), b = scanner.nextInt(), w = scanner.nextInt();
      adj[a].add(new Edge(b, w));
      adj[b].add(new Edge(a, w));
    }

    PriorityQueue<Edge> pq = new PriorityQueue<Edge>(n, (a, b) -> a.w - b.w);
    boolean[] vis = new boolean[n + 1];
    pq.offer(new Edge(1, 0));

    while (!pq.isEmpty()) {
      Edge curr = pq.poll();
      if (!vis[curr.v]) {
        c += curr.w;
        vis[curr.v] = true;
        for (Edge e : adj[curr.v]) {
          if (!vis[e.v]) pq.offer(e);
        }
      }
    }

    System.out.println(c);
  }
}

class Edge {
  int v, w;
  public Edge(int v, int w) {
    this.v = v;
    this.w = w;
  }
}
