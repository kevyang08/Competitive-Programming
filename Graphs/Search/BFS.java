import java.util.*;

class Main {
  static int n, m;
  static ArrayList<Integer>[] adj;
  //static boolean[] pushed;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    n = scanner.nextInt();
    m = scanner.nextInt();
    adj = new ArrayList[n + 1];
    // pushed = new boolean[n + 1];

    for (int i = 1; i <= n; i++) {
      adj[i] = new ArrayList<Integer>();
    }
    
    for (int i = 0; i < m; i++) {
      int x = scanner.nextInt(), y = scanner.nextInt();
      adj[x].add(y);
      adj[y].add(x);
    }

    int from = scanner.nextInt(), to = scanner.nextInt();
    int dist = bfs(from, to);
    System.out.println(dist == 0 ? "Node " + from + " is not connected to node " + to : "The shortest distance from node " + from + " to node " + to + " is " + dist);
  }
  public static int bfs(int from, int to) {
    int[] dist = new int[n + 1];
    Queue<Integer> q = new LinkedList<Integer>();
    q.offer(from);
    while (!q.isEmpty()) {
      int curr = q.poll();
      for (int v : adj[curr]) {
        //if (!pushed[v]) {
        if (dist[v] == 0) {
          q.offer(v);
          // pushed[v] = true;
          dist[v] = dist[curr] + 1;
        }
        //if (pushed[to]) {
        if (dist[to] != 0) {
          break;
        }
      }
    }
    return dist[to];
  }
}
