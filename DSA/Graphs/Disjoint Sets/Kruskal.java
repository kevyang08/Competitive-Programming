import java.util.*;

class Main {
  static int[] id;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt(), m = scanner.nextInt(), c = 0;
    id = new int[n];
    Arrays.fill(id, -1);
    Edge[] edges = new Edge[m];

    for (int i = 0; i < m; i++) {
      int x = scanner.nextInt() - 1, y = scanner.nextInt() - 1, w = scanner.nextInt();
      edges[i] = new Edge(x, y, w);
    }
    Arrays.sort(edges, (a, b) -> a.w - b.w);
    
    for (Edge e : edges) {
      if (id[e.u] == -1 || find(e.u) != find(e.v)) {
        c += e.w;
        union(e.u, e.v);
      }
    }

    System.out.println(c);
  }
  public static int find(int x) {
    return id[x] < 0 ? x : (id[x] = find(id[x]));
  }
  public static void union(int x, int y) {
    if (id[x = find(x)] < id[y = find(y)]) {
      id[x] += id[y];
      id[y] = x;
    }
    else {
      id[y] += id[x];
      id[x] = y;
    }
  }
}

class Edge {
  int u, v, w;
  public Edge(int u, int v, int w) {
    this.u = u;
    this.v = v;
    this.w = w;
  }
}
