import java.util.*;

class Main {
  static int n, m;
  static ArrayList<Integer>[] adj;
  static boolean[] vis;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    n = scanner.nextInt();
    m = scanner.nextInt();
    adj = new ArrayList[n + 1];
    vis = new boolean[n + 1];

    for (int i = 1; i <= n; i++) {
      adj[i] = new ArrayList<Integer>();
    }

    for (int i = 0; i < m; i++) {
      int x = scanner.nextInt(), y = scanner.nextInt();
      adj[x].add(y);
      adj[y].add(x);
    }

    dfs(1);
    System.out.println(vis[n] ? "The first node is connected to the last node" : "The first node is not connected to the last node");
  }
  public static void dfs(int x) {
    vis[x] = true;
    if (x == n) {
      return;
    }
    for (int v : adj[x]) {
      if (!vis[v]) {
        dfs(v);
      }
      if (vis[n]) {
        return;
      }
    }
  }
}
