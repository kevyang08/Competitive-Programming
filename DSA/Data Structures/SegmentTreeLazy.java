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
  public static void update(int ql, int qr, int l, int r, int v, int idx) {
    // lazy updates allow us to apply updates to nodes while we answer other queries, ensuring O(logN) time for range updates
    if (lazy[idx] != 0) { // pending lazy updates
      st[idx] += lazy[idx] * (r - l + 1); // apply pending lazy updates to current node
      if (l != r) { // if not leaf node, marks children node as lazy
        lazy[2 * idx] += lazy[idx];
        lazy[2 * idx + 1] += lazy[idx];
      }
      lazy[idx] = 0; // removing the lazy value because it is no longer needed
    }
    if (ql > r || qr < l) { // current node is out of range of query
      return;
    }
    if (l >= ql && r <= qr) { // current node is fully within query range
      st[idx] += v * (r - l + 1); // applies lazy value to current node
      if (l != r) { // if not leaf node, marks children node as lazy
        lazy[2 * idx] += v;
        lazy[2 * idx + 1] += v;
      }
      return;
    }
    int m = (l + r)/2; // if current node is partially within range, recursively update children nodes
    update(ql, qr, l, m, v, 2 * idx);
    update(ql, qr, m + 1, r, v, 2 * idx + 1);
    st[idx] = st[2 * idx] + st[2 * idx + 1];
  }
  public static int query(int ql, int qr, int l, int r, int idx) {
    if (lazy[idx] != 0) { // first checks for pending lazy updates
      st[idx] += lazy[idx] * (r - l + 1); // apply pending lazy updates to current node
      if (l != r) { // if not leaf node, marks children node as lazy
        lazy[2 * idx] += lazy[idx];
        lazy[2 * idx + 1] += lazy[idx];
      }
      lazy[idx] = 0; // removes lazy value from current node as it is no longer needed
    }
    if (l >= ql && r <= qr) { // if current node is fully within range, returns its value
      return st[idx];
    }
    if (ql > r || qr < l) { // if current node is not within range, returns nothing
      return 0;
    }
    int m = (l + r)/2; // if current node is partially within range, recursively traverses children node
    return query(ql, qr, l, m, 2 * idx) + query(ql, qr, m + 1, r, 2 * idx + 1);
  }
}
