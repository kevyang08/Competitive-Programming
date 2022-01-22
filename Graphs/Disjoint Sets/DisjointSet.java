import java.util.*;

class Main {
  static int[] id;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt(), m = scanner.nextInt();
    id = new int[n];
    Arrays.fill(id, -1);
    
    for (int i = 0; i < m; i++) {
      int x = scanner.nextInt() - 1, y = scanner.nextInt() - 1;
      union(x, y);
    }

    System.out.println(Arrays.toString(id));
  }
  public static int find(int x) {
    return id[x] < 0 ? x : (id[x] = find(id[x]));
  }
  public static void union(int x, int y) {
    if (id[x = find(x)] < id[y = find(y)]) {
      id[x] += id[y];
      id[y] = x;
    }
    else {
      id[y] += id[x];
      id[x] = y;
    }
  }
}
