import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    int[] arr = new int[n];
    
    for (int i = 0; i < n; i++) {
      arr[i] = scanner.nextInt();
    }

    heapsort(arr);
    System.out.println(Arrays.toString(arr));
  }
  public static void heapsort(int[] arr) {
    Heap heap = new Heap(arr.length);
    for (int i : arr) heap.add(i);
    for (int i = 0; i < arr.length; i++) arr[i] = heap.poll();
  }
}

class Heap {
  private int[] heap;
  private int n = 0;
  public Heap(int sz) {
    heap = new int[sz + 1];
  }
  private void swap(int i, int j) {
    int temp = heap[j];
    heap[j] = heap[i];
    heap[i] = temp;
  }
  private void heapUp(int i) {
    if (i/2 > 0 && heap[i] < heap[i/2]) {
      swap(i, i/2);
      heapUp(i/2);
    }
  }
  private void heapDown(int i) {
    if (i * 2 <= n) {
      if (i * 2 + 1 <= n && heap[i * 2 + 1] < heap[i * 2] && heap[i * 2 + 1] < heap[i]) {
        swap(i, i * 2 + 1);
        heapDown(i * 2 + 1);
      }
      else if (heap[i * 2] < heap[i]) {
        swap(i, i * 2);
        heapDown(i * 2);
      }
    }
  }
  public void add(int x) {
    heap[++n] = x;
    heapUp(n);
  }
  public int poll() {
    int x = heap[1];
    heap[1] = heap[n--];
    heapDown(1);
    return x;
  }
}
