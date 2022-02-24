import java.util.*;

class Main {
  static int[] tree;
  static int n;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    n = scanner.nextInt();
    tree = new int[2 * n];

    for (int i = 0; i < n; i++) {
      tree[n + i] = scanner.nextInt();
    }

    for (int i = n - 1; i > 0; i--) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    int q = scanner.nextInt();

    for (int i = 0; i < q; i++) {
      int op = scanner.nextInt();
      if (op == 1) {
        int x = scanner.nextInt(), v = scanner.nextInt();
        update(x, v);
      }
      else {
        int l = scanner.nextInt() - 1, r = scanner.nextInt();
        System.out.println(query(l, r));
      }
    }

    System.out.println(Arrays.toString(tree));
  }
  // probably never going to use this again until i actually understand what it does and figure out how to update lazily
  public static void update(int x, int v) {
    x += n - 1;
    tree[x] = v;
    for (int i = x/2; i > 0; i /= 2) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }
  public static int query(int l, int r) {
    int sum = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l%2 == 1) sum += tree[l++];
      if (r%2 == 1) sum += tree[--r];
    }
    return sum;
  }
}
