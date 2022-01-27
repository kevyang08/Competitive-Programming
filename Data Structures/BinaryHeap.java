import java.util.*;

class Main {
  static int[] heap = new int[1000001];
  static int n = 0;
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int q = scanner.nextInt();
    for (int i = 0; i < q; i++) {
      char op = scanner.next().charAt(0);
      if (op == 'a') {
        int x = scanner.nextInt();
        add(x);
      }
      else if (op == 's') {
        System.out.println(n);
      }
      else if (op == 'p') {
        System.out.println(poll());
      }
    }

    for (int i = 1, j = 1; i <= n; j += i, i *= 2) {
      System.out.println();
      for (int k = j; k < j + i && k <= n; k++) {
        System.out.printf("%" + (1 << (int)Math.ceil(Math.log(n)/Math.log(2)))/i + "s", heap[k]);
      }
      System.out.println();
      for (int k = j; k < j + i && k <= n; k++) {
        if (k * 2 <= n) System.out.printf("%" + ((1 << (int)Math.ceil(Math.log(n)/Math.log(2)))/i/2 + 1) + "s", "/");
        if (k * 2 + 1 <= n) System.out.printf("%" + ((1 << (int)Math.ceil(Math.log(n)/Math.log(2)))/i/2 - 1) + "s", "|");
      }
    }
  }
  public static void swap(int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
    if (j/2 > 0 && heap[j] < heap[j/2]) swap(j, j/2);
  }
  public static void remove(int i) {
    if (i * 2 <= n) {
      if (i * 2 + 1 <= n && heap[i * 2 + 1] < heap[i * 2]) {
        heap[i] = heap[i * 2 + 1];
        remove(i * 2 + 1);
      }
      else {
        heap[i] = heap[i * 2];
        remove(i * 2);
      }
    }
  }
  public static void add(int x) {
    heap[++n] = x;
    if (n/2 > 0 && heap[n] < heap[n/2]) swap(n, n/2);
  }
  public static int poll() {
    int x = heap[1];
    remove(1);
    n--;
    return x;
  }
}
