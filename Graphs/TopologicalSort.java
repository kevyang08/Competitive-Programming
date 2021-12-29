import java.util.*;

class Main {
  static ArrayList<Integer>[] adj;
  static int n, m;
  static boolean[] vis;
  static boolean cycle = false;
  static HashSet<Integer> currNodes = new HashSet<Integer>();
  static ArrayList<Integer> list = new ArrayList<Integer>();
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
      int a = scanner.nextInt(), b = scanner.nextInt();
      adj[a].add(b);
    }

    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        dfs(i);
      }
    }

    if (cycle) System.out.println(-1);
    else {
      for (int i = list.size() - 1; i >= 0; i--) {
        System.out.print(i == 0 ? list.get(i) : list.get(i) + " ");
      }
      System.out.println();
    }
  }
  public static void dfs(int x) {
    for (int i : adj[x]) {
      if (!vis[i]) {
        if (currNodes.contains(i)) {
          cycle = true;
          return;
        }
        currNodes.add(i);
        dfs(i);
        if (cycle) return;
        currNodes.remove(i);
      }
    }

    vis[x] = true;
    list.add(x);
  }
}
