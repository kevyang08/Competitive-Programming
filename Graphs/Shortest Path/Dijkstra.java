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
      int x = scanner.nextInt(), y = scanner.nextInt(), w = scanner.nextInt();
      adj[x].add(new Edge(y, w));
      adj[y].add(new Edge(x, w));
    }

    int from = scanner.nextInt(), to = scanner.nextInt();
    int dist = getDist(from, to);
    System.out.println(dist == Integer.MAX_VALUE ? "Node " + from + " is not connected to node " + to : "The shortest distance from node " + from + " to node " + to + " is " + dist);
  }
  public static int getDist(int from, int to) {
    int[] dist = new int[n + 1], parent = new int[n + 1];
    Arrays.fill(dist, Integer.MAX_VALUE);
    dist[from] = 0;
    PriorityQueue<Pair> q = new PriorityQueue<Pair>(n,(a,b) -> a.value - b.value);
    q.offer(new Pair(from, 0));
    
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
    
    Stack<Integer> res = new Stack<Integer>();
    int i = to;
    while (i != 0) {
      res.push(i);
      i = parent[i];
    }
    while (!res.isEmpty()) {
      System.out.print(res.pop() + " ");
    }
    System.out.println();

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

class Pair {
  int key, value;
  public Pair(int key, int value) {
    this.key = key;
    this.value = value;
  }
}
