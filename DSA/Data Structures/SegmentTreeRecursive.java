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
    // the current node covers range [l:r]
    if (l == r) { // current node is leaf node
      st[idx] = arr[l];
      return;
    }
    int m = (l + r)/2; // build children nodes
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
    if (u <= m) { // node to update is within range [l:m]
      update(l, m, u, v, 2 * idx);
    }
    else { // node to update is within range [m + 1:r]
      update(m + 1, r, u, v, 2 * idx + 1);
    }
    st[idx] = st[2 * idx] + st[2 * idx + 1];
  }
  public static int query(int ql, int qr, int l, int r, int idx) {
    if (l >= ql && r <= qr) { // if current node is fully within range, we can just return its value
      return st[idx];
    }
    if (ql > r || qr < l) { // if current node is out of range, return nothing
      return 0;
    }
    int m = (l + r)/2; // if current node is partially in range, keep traversing the tree
    return query(ql, qr, l, m, 2 * idx) + query(ql, qr, m + 1, r, 2 * idx + 1);
  }
}
