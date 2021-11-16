import java.util.*;

class Main {
  public static int[] tree;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    int[] arr = new int[n];
    tree = new int[n + 1];
    char q = scanner.next().toUpperCase().charAt(0);

    while (q != 'E') {
      if (q == 'U') {
        int x = scanner.nextInt(), v = scanner.nextInt();
        update(x, v - arr[x - 1]);
        arr[x - 1] = v;
      }
      else if (q == 'S') {
        int l = scanner.nextInt(), r = scanner.nextInt();
        System.out.println(getSum(r) - getSum(l - 1));
      }
      q = scanner.next().toUpperCase().charAt(0);
    }
    System.out.println(Arrays.toString(arr));
    System.out.println(Arrays.toString(tree));
  }
  public static void update(int x, int v) {
    while (x < tree.length) {
      tree[x] += v;
      x += x & -x;
    }
  }
  public static int getSum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
      sum += tree[i];
    }
    return sum;
  }
}
