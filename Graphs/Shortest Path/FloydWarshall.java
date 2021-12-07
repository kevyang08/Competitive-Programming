import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt(), m = scanner.nextInt(), q = scanner.nextInt();
    int[][] adj = new int[n][n];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        adj[i][j] = 0x3f3f3f3f;
      }
      adj[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
      int x = scanner.nextInt() - 1, y = scanner.nextInt() - 1, w = scanner.nextInt();
      adj[x][y] = w;
      adj[y][x] = w;
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (adj[i][j] > adj[i][k] + adj[k][j]) {
            adj[i][j] = adj[i][k] + adj[k][j];
          }
        }
      }
    }

    for (int i = 0; i < q; i++) {
      int x = scanner.nextInt() - 1, y = scanner.nextInt() - 1;
      System.out.println(adj[x][y] == 0x3f3f3f3f ? -1 : adj[x][y]);
    }
  }
}
