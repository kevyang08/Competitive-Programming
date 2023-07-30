import java.util.*;
 
public class Main {
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
      int x = scanner.nextInt(), y = scanner.nextInt(), w = scanner.nextInt();
      adj[x].add(new Edge(y, w));
      adj[y].add(new Edge(x, w));
    }
 
    getDist();
  }
  public static void getDist() {
    long[] dist = new long[n + 1];
    int[] parent = new int[n + 1];
    Arrays.fill(dist, Long.MAX_VALUE);
    dist[1] = 0;
    PriorityQueue<Pair> q = new PriorityQueue<Pair>(n,(a,b) -> (int)(a.value - b.value));
    q.offer(new Pair(1, 0));
    while (!q.isEmpty()) {
      int curr = q.poll().key;
      for (Edge v : adj[curr]) {
        if (dist[v.to] > dist[curr] + v.dist) {
          dist[v.to] = dist[curr] + v.dist;
          q.offer(new Pair(v.to, dist[v.to]));
          parent[v.to] = curr;
        }
      }
    }
    if (dist[n] == Long.MAX_VALUE) {
        System.out.println(-1);
    }
    else {
        Stack<Integer> res = new Stack<Integer>();
        int i = n;
        while (i != 0) {
            res.push(i);
            i = parent[i];
        }
        while (!res.isEmpty()) {
            System.out.print(res.pop() + " ");
        }
    }
  }
}
 
class Edge {
  int to, dist;
  public Edge(int to, int dist) {
    this.to = to;
    this.dist = dist;
  }
}
 
class Pair {
    int key;
    long value;
    public Pair(int key, long value) {
        this.key = key;
        this.value = value;
    }
}
