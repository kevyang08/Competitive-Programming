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
      System.out.print(i + " ->");
      for (int j = 0; j < n; j++) {
        if (adj[i][j] > 0) {
          System.out.print(" " + j);
        }
      }
      System.out.println();
    }
  }
}
