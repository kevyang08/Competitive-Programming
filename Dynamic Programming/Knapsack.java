import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt(), c = scanner.nextInt();
    int[] v = new int[n + 1], w = new int[n + 1];
    int[][] dp = new int[n + 1][c + 1];

    for (int i = 1; i <= n; i++) {
      v[i] = scanner.nextInt();
      w[i] = scanner.nextInt();
    }

    // setting up dp table
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= c; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= w[i]) {
          dp[i][j] = Math.max(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
        }
      }
    }

    System.out.println(dp[n][c]);
  }
}
