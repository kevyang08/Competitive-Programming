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
    for (int i = 0; i < arr.length; i++) {
      heapUp(arr, i);
    }
    for (int i = arr.length - 1; i > 0; i--) {
      swap(arr, i, 0);
      heapDown(arr, i, 0);
    }
  }
  public static void heapUp(int[] arr, int i) {
    while ((i + 1)/2 - 1 >= 0 && arr[i] > arr[(i + 1)/2 - 1]) {
      swap(arr, i, (i + 1)/2 - 1);
      i = (i + 1)/2 - 1;
    }
  }
  public static void heapDown(int[] arr, int i, int j) {
    while (j * 2 + 1 < i) {
      if (j * 2 + 2 < i && arr[j * 2 + 2] > arr[j * 2 + 1] && arr[j * 2 + 2] > arr[j]) {
        swap(arr, j, j * 2 + 2);
        j = j * 2 + 2;
      }
      else if (arr[j * 2 + 1] > arr[j]) {
        swap(arr, j, j * 2 + 1);
        j = j * 2 + 1;
      }
      else break;
    }
  }
  public static void swap(int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}
