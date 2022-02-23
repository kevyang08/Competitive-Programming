import java.util.*;

class Main {
  static int[] st;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    st = new int[4 * n];
    int[] arr = new int[n + 1];

    for (int i = 1; i <= n; i++) {
      arr[i] = scanner.nextInt();
    }
    build(arr, 1, n, 1);

    int q = scanner.nextInt();
    while(q-- > 0) {
      int op = scanner.nextInt();
      if (op == 1) {
        int x = scanner.nextInt(), v = scanner.nextInt();
        update(1, n, x, v, 1);
      }
      else {
        int l = scanner.nextInt(), r = scanner.nextInt();
        System.out.println(query(l, r, 1, n, 1));
      }
    }
    System.out.println(Arrays.toString(st));
  }
  public static void build(int[] arr, int l, int r, int idx) {
    if (l == r) {
      st[idx] = arr[l];
      return;
    }
    int m = (l + r)/2;
    build(arr, l, m, 2 * idx);
    build(arr, m + 1, r, 2 * idx + 1);
    st[idx] = st[2 * idx] + st[2 * idx + 1];
  }
  public static void update(int l, int r, int u, int v, int idx) {
    if (l == r && l == u) {
      st[idx] = v;
      return;
    }
    int m = (l + r)/2;
    if (u <= m) {
      update(l, m, u, v, 2 * idx);
    }
    else {
      update(m + 1, r, u, v, 2 * idx + 1);
    }
    st[idx] = st[2 * idx] + st[2 * idx + 1];
  }
  public static int query(int ql, int qr, int l, int r, int idx) {
    if (l >= ql && r <= qr) {
      return st[idx];
    }
    if (ql > r || qr < l) {
      return 0;
    }
    int m = (l + r)/2;
    return query(ql, qr, l, m, 2 * idx) + query(ql, qr, m + 1, r, 2 * idx + 1);
  }
}
