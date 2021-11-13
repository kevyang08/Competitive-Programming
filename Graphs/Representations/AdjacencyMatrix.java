import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    int[][] adj = new int[n][n];

    while (true) {
      int i = scanner.nextInt(), j = scanner.nextInt(), w = scanner.nextInt();
      if (i-- == 0 || j-- == 0 || w == 0) {
        break;
      }
      adj[i][j] = adj[j][i] = w;
    }

    for (int i = 0; i < n; i++) {
      System.out.println(Arrays.toString(adj[i]));
    }
  }
}
