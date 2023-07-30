import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    ArrayList<Edge>[] adj = new ArrayList[n];

    for (int i = 0; i < n; i++) {
      adj[i] = new ArrayList<Edge>();
    }

    while (true) {
      int i = scanner.nextInt(), j = scanner.nextInt(), w = scanner.nextInt();
      if (i-- == 0 || j-- == 0 || w == 0) {
        break;
      }
      adj[i].add(new Edge(j, w));
      adj[j].add(new Edge(i, w));
    }

    for (int i = 0; i < n; i++) {
      System.out.print(i + " ->");
      for (Edge e : adj[i]) {
        System.out.print(" " + e.to);
      }
      System.out.println();
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
