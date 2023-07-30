import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt(), q = scanner.nextInt();
    int[][] st = new int[log2(n) + 1][n];

    for (int i = 0; i < n; i++) st[0][i] = scanner.nextInt();

    for (int i = 1; i < st.length; i++) {
      for (int j = 0; j + (1 << (i - 1)) < n; j++) {
        st[i][j] = Math.min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }

    for (int i = 0; i < q; i++) {
      int l = scanner.nextInt() - 1, r = scanner.nextInt(), j = log2(r - l); // assume array is 1-indexed
      System.out.println(Math.min(st[j][l], st[j][r - (1 << j)]));
    }

    for (int i = 0; i < st.length; i++) System.out.println(Arrays.toString(st[i]));
  }
  public static int log2(int n) { // log base 2
    return 31 - Integer.numberOfLeadingZeros(n);
  }
}
