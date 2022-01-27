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
    int temp = heap[j];
    heap[j] = heap[i];
    heap[i] = temp;
  }
  public static void heapUp(int i) {
    if (i/2 > 0 && heap[i] < heap[i/2]) {
      swap(i, i/2);
      heapUp(i/2);
    }
  }
  public static void heapDown(int i) {
    if (i * 2 <= n) {
      if (i * 2 + 1 <= n && heap[i * 2 + 1] < heap[i * 2]) {
        swap(i, i * 2 + 1);
        heapDown(i * 2 + 1);
      }
      else {
        swap(i, i * 2);
        heapDown(i * 2);
      }
    }
  }
  public static void add(int x) {
    heap[++n] = x;
    heapUp(n);
  }
  public static int poll() {
    int x = heap[1];
    heap[1] = heap[n--];
    heapDown(1);
    return x;
  }
}
