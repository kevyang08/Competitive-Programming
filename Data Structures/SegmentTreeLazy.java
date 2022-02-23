import java.util.*;

class Main {
  static int[] st, lazy;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    st = new int[4 * n];
    lazy = new int[4 * n];
    int[] arr = new int[n + 1];

    for (int i = 1; i <= n; i++) {
      arr[i] = scanner.nextInt();
    }
    build(arr, 1, n, 1);

    int q = scanner.nextInt();
    while(q-- > 0) {
      int op = scanner.nextInt();
      if (op == 1) {
        int l = scanner.nextInt(), r = scanner.nextInt(), v = scanner.nextInt();
        update(l, r, 1, n, v, 1);
      }
      else {
        int l = scanner.nextInt(), r = scanner.nextInt();
        System.out.println(query(l, r, 1, n, 1));
      }
    }
    System.out.println(Arrays.toString(st));
    System.out.println(Arrays.toString(lazy));
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
  public static void update(int ql, int qr, int l, int r, int v, int idx) {
    if (lazy[idx] != 0) {
      st[idx] += lazy[idx] * (r - l + 1);
      if (l != r) {
        lazy[2 * idx] += lazy[idx];
        lazy[2 * idx + 1] += lazy[idx];
      }
      lazy[idx] = 0;
    }
    if (l > r || ql > r || qr < l) {
      return;
    }
    if (l >= ql && r <= qr) {
      st[idx] += v * (r - l + 1);
      if (l != r) {
        lazy[2 * idx] += v;
        lazy[2 * idx + 1] += v;
      }
      return;
    }
    int m = (l + r)/2;
    update(ql, qr, l, m, v, 2 * idx);
    update(ql, qr, m + 1, r, v, 2 * idx + 1);
    st[idx] = st[2 * idx] + st[2 * idx + 1];
  }
  public static int query(int ql, int qr, int l, int r, int idx) {
    if (lazy[idx] != 0) {
      st[idx] += lazy[idx] * (r - l + 1);
      if (l != r) {
        lazy[2 * idx] += lazy[idx];
        lazy[2 * idx + 1] += lazy[idx];
      }
      lazy[idx] = 0;
    }
    if (l >= ql && r <= qr) {
      return st[idx];
    }
    if (l > r || ql > r || qr < l) {
      return 0;
    }
    int m = (l + r)/2;
    return query(ql, qr, l, m, 2 * idx) + query(ql, qr, m + 1, r, 2 * idx + 1);
  }
}
