import java.util.*;

class Main {
  static int n, m;
  static Edge[] edges;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    n = scanner.nextInt();
    m = scanner.nextInt();
    edges = new Edge[m];
    
    for (int i = 0; i < m; i++) {
      int x = scanner.nextInt(), y = scanner.nextInt(), w = scanner.nextInt();
      edges[i] = new Edge(x, y, w);
    }

    int from = scanner.nextInt(), to = scanner.nextInt();
    int dist = getDist(from, to);
    System.out.println(dist == 0x3f3f3f3f ? "Node " + from + " is not connected to node " + to : dist == Integer.MIN_VALUE ? "Negative cycle detected" : "The shortest distance from node " + from + " to node " + to + " is " + dist);
  }
  public static int getDist(int from, int to) {
    int[] dist = new int[n + 1];
    Arrays.fill(dist, 0x3f3f3f3f);
    dist[from] = 0;
    
    for (int i = 1; i <= n; i++) {
      for (Edge e : edges) {
        if (dist[e.to] > dist[e.from] + e.dist) {
          dist[e.to] = dist[e.from] + e.dist;
          if (i == n) return Integer.MIN_VALUE;
        }
      }
    }

    return dist[to];
  }
}

class Edge {
  int from, to, dist;
  public Edge(int from, int to, int dist) {
    this.from = from;
    this.to = to;
    this.dist = dist;
  }
}
