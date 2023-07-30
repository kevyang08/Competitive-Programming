import java.util.*;

class Main {
  static int n, m;
  static ArrayList<Edge>[] adj;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    n = scanner.nextInt();
    m = scanner.nextInt();
    adj = new ArrayList[n + 1];

    for (int i = 1; i <= n; i++) {
      adj[i] = new ArrayList<Edge>();
    }

    for (int i = 0; i < m; i++) {
      int a = scanner.nextInt(), b = scanner.nextInt(), w = scanner.nextInt();
      adj[a].add(new Edge(b, w));
    }

    int from = scanner.nextInt(), to = scanner.nextInt(), dist = getDist(from, to);
    System.out.println(dist == 0x3f3f3f3f ? "Node " + from + " is not connected to node " + to : "The shortest distance from node " + from + " to node " + to + " is " + dist);
  }
  public static int getDist(int from, int to) {
    int[] dist = new int[n + 1];
    boolean[] inq = new boolean[n + 1];
    Queue<Integer> q = new LinkedList<Integer>();
    Arrays.fill(dist, 0x3f3f3f3f);
    dist[from] = 0;
    q.offer(from);

    while (!q.isEmpty()) {
      int curr = q.poll();
      inq[curr] = false;
      for (Edge e : adj[curr]) {
        if (dist[e.to] > dist[curr] + e.dist) {
          dist[e.to] = dist[curr] + e.dist;
          if (!inq[e.to]) {
            q.offer(e.to);
            inq[e.to] = true;
          }
        }
      }
    }

    return dist[to];
  }
}

class Edge {
  int to, dist;
  public Edge(int to, int dist) {
    this.to = to;
    this.dist = dist;
  }
}
