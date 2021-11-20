import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    int[] arr = new int[n];
    
    for (int i = 0; i < n; i++) {
      arr[i] = scanner.nextInt();
    }

    quickSort(arr, 0, n - 1);
    System.out.println(Arrays.toString(arr));
  }
  public static void quickSort(int[] arr, int l, int r) {
    if (l < r) {
      int i = partition(arr, l, r);
      quickSort(arr, l, i - 1);
      quickSort(arr, i + 1, r);
    }
  }
  public static int partition(int[] arr, int l, int r) {
    int pivot = arr[(l + r)/2], i = l;
    swap(arr, l, (l + r)/2);
    for (int j = i + 1; j <= r; j++) {
      if (arr[j] < pivot) {
        swap(arr, ++i, j);
      }
    }
    swap(arr, i, l);
    return i;
  }
  public static void swap(int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}
