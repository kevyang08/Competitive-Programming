import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    
    int n = scanner.nextInt();
    int[] arr = new int[n];
    
    for (int i = 0; i < n; i++) {
      arr[i] = scanner.nextInt();
    }

    timSort(arr);
    System.out.println(Arrays.toString(arr));
  }
  public static void timSort(int[] arr) {
    int[] temp = new int[arr.length];
    for (int i = 0; i < arr.length; i += 64) insertionSort(arr, i, Math.min(arr.length, i + 64));
    for (int i = 64; i < arr.length; i *= 2) {
      for (int j = 0; j < arr.length; j += 2 * i) {
        merge(arr, temp, j, Math.min(j + 2 * i, arr.length), j + i);
      }
    }
  }
  public static void merge(int[] arr, int[] temp, int l, int r, int mid) {
    for (int i = l; i < r; i++) temp[i] = arr[i];
    for (int i = l, j = mid, k = l; k < r; k++) {
      if (j >= r || i < mid && temp[i] < temp[j]) arr[k] = temp[i++];
      else arr[k] = temp[j++];
    }
  }
  public static void insertionSort(int[] arr, int l, int r) {
    for (int i = l + 1; i < r; i++) {
      int current = arr[i];
      for (int j = i - 1; j >= l && arr[j] > current; j--) {
        arr[j + 1] = arr[j];
        arr[j] = current;
      }
    }
  }
}
